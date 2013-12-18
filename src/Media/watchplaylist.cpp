#include "watchplaylist.h"
#include "Utilities/logger.h"
#include "coremanager.h"

#include <QSettings>
#include <QDir>
#include <QtConcurrent/QtConcurrent>
#include <QMutexLocker>

WatchPlaylist::WatchPlaylist(QString path, QObject *parent) :
    AbstractPlaylist(parent)
{
//    Logger::log("New WatchPlaylist " + name + " - " + path, LOG_DEBUG);

    m_type = WATCHPLAYLIST;
    m_path.setPath(path);
    m_name = m_path.dirName();
    m_watchfolder = new QFileSystemWatcher();
    m_collection = new Collection();
    qDebug() << "WatchPlaylist " << this << " created with Collection " << m_collection;
    _update();
}

WatchPlaylist::~WatchPlaylist()
{
    _disable();
    delete m_collection;
    delete m_watchfolder;
}

void    WatchPlaylist::update()
{
    QSettings settings;

    Logger::log("WatchPlaylist - update", LOG_DEBUG);

    if (settings.value("watchFolderActivated").toBool() == true)
        _update();
    else
        _disable();
}

void    WatchPlaylist::_refresh(QString path)
{
    m_mutex.lock();
    Logger::log("WatchPlaylist - _refresh - watchFolder modified at path " + path, LOG_DEBUG);
    if (m_collection->getTracks() == NULL)
        m_collection->reset();
    CoreManager::instance()->database()->importEngine()->importPath(path, m_collection);
    m_mutex.unlock();
    updated();
}

void WatchPlaylist::insert(int, const Track *)
{

}

void WatchPlaylist::append(const Track *)
{

}

void WatchPlaylist::remove(int)
{

}

QObject *WatchPlaylist::get(int)
{
}

void WatchPlaylist::setProperty(int index, const QString &property, const QVariant &value)
{

}

void    WatchPlaylist::_update()
{
    if (m_path.exists())
    {
        Logger::log("WatchPlaylist - Path correct : " +  m_path.absolutePath() +  LOG_DEBUG);
        m_watchfolder->removePaths(m_watchfolder->directories());
        m_watchfolder->addPath(m_path.absolutePath());

        if (QObject::receivers(SIGNAL(directoryChanged(QString))) == 0) {
            Logger::log("WatchPlaylist - _update - signal not set -> connecting", LOG_DEBUG);
            connect(m_watchfolder, SIGNAL(directoryChanged(QString)), this, SLOT(_refresh(QString)));
            Logger::log("WatchPlaylist - _update - signal not set -> connected", LOG_DEBUG);
        }

        // Create a Job in job manager
        Logger::log("WatchPlaylist - creating new thread for refresh", LOG_DEBUG);
        QtConcurrent::run(this, &WatchPlaylist::_refresh, m_path.absolutePath());
    }
    else
    {
        Logger::log("WatchPlaylist - Path incorrect : " + m_path.absolutePath(), LOG_WARNING);
    }
}

void    WatchPlaylist::_disable()
{
    Logger::log("WatchPlaylist - _disable", LOG_DEBUG);
    if (QObject::receivers(SIGNAL(directoryChanged(QString))) > 0)
        disconnect(m_watchfolder, SIGNAL(directoryChanged(QString)), this, SLOT(_refresh(QString)));
    m_watchfolder->removePaths(m_watchfolder->directories());
}

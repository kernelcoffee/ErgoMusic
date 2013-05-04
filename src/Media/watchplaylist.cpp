#include "watchplaylist.h"
#include "Utilities/logger.h"
#include "coremanager.h"

#include <QSettings>
#include <QDir>
#include <QtConcurrent/QtConcurrent>
#include <QMutexLocker>

WatchPlaylist::WatchPlaylist(QObject *parent) :
    AbstractPlaylist(parent)
{
    QSettings   settings;

    Logger::log("WatchPlaylist - Constructor", LOG_DEBUG);

    m_watchfolder = new QFileSystemWatcher();

    if (settings.value("watchFolderActivated").toBool() == true) {
        _update();
    }
    m_viewType = ViewWidget::LIST;
}

WatchPlaylist::~WatchPlaylist()
{
    delete m_watchfolder;
    _disable();
}

void    WatchPlaylist::update()
{
    QSettings settings;

    Logger::log("WatchPlaylist - update", LOG_DEBUG);

    if (settings.value("watchFolderActivated").toBool() == true)
    {
        _update();
    }
    else
        _disable();
}

void    WatchPlaylist::_refresh(QString path)
{
    m_mutex.lock();
    Logger::log("WatchPlaylist - _refresh - watchFolder modified at path " + path, LOG_DEBUG);
    if (m_list == NULL)
        delete m_list;
    m_list = CoreManager::instance()->database()->importEngine()->importPath(path);
    m_mutex.unlock();
    updated();
}

void    WatchPlaylist::_update()
{
    QSettings   settings;
    QDir        watchFolder(settings.value("watchFolder").toString());

    if (watchFolder.exists())
    {
        Logger::log("WatchPlaylist - Path correct : " + watchFolder.absolutePath(), LOG_DEBUG);
        m_watchfolder->removePaths(m_watchfolder->directories());
        m_watchfolder->addPath(watchFolder.absolutePath());

        if (QObject::receivers(SIGNAL(directoryChanged(QString))) == 0) {
            Logger::log("WatchPlaylist - _update - signal not set -> connecting", LOG_DEBUG);
            connect(m_watchfolder, SIGNAL(directoryChanged(QString)), this, SLOT(_refresh(QString)));
        }
        QtConcurrent::run(this, &WatchPlaylist::_refresh, settings.value("watchFolder").toString());
       // m_watchfolder->directoryChanged(settings.value("watchFolder").toString());
    }
    else
    {
        Logger::log("WatchPlaylist - Path incorrect : " + watchFolder.absolutePath(), LOG_WARNING);
    }
}

void    WatchPlaylist::_disable()
{
    Logger::log("WatchPlaylist - _disable", LOG_DEBUG);
    if (QObject::receivers(SIGNAL(directoryChanged(QString))) > 0)
        disconnect(m_watchfolder, SIGNAL(directoryChanged(QString)), this, SLOT(_refresh(QString)));
    m_watchfolder->removePaths(m_watchfolder->directories());
}

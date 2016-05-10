#include "watchplaylist.h"
#include <QDir>

#include <QDebug>

WatchPlaylist::WatchPlaylist(QString path, QObject *parent) :
    AbstractPlaylist(parent)
  , m_path(path)
  , m_status(Idle)
{
    qDebug() << "WatchPlaylist created : " << m_path;
    _update();
}

WatchPlaylist::WatchPlaylist(int id, QString name, QString path, QObject *parent) :
    AbstractPlaylist(parent)
{
    m_id = id;
    m_name = name;
    m_path = path;
    _update();
}

WatchPlaylist::~WatchPlaylist()
{

}

QString WatchPlaylist::path() const
{
    return m_path;
}

WatchPlaylist::Status WatchPlaylist::status() const
{
    return m_status;
}

void WatchPlaylist::clear()
{
    qDeleteAll(m_tracks);
    m_tracks.clear();
    emit cleared();
}

void    WatchPlaylist::refresh()
{
    qDebug();
    emit requestRefresh();
}

void WatchPlaylist::setStatus(WatchPlaylist::Status status)
{
    if (m_status == status)
        return;
    m_status = status;
    emit statusChanged(status);
}

void    WatchPlaylist::_update()
{
    QDir dir(m_path);

    if (dir.exists())
    {
        qDebug() << "Path correct : " +  dir.absolutePath();
        m_watchfolder.removePaths(m_watchfolder.directories());
        m_watchfolder.addPath(dir.absolutePath());
        m_name = dir.dirName();

        if (QObject::receivers(SIGNAL(directoryChanged(QString))) == 0) {
            connect(&m_watchfolder, &QFileSystemWatcher::directoryChanged,
                    this, &WatchPlaylist::requestRefresh);
        }
    }
    else
    {
        qDebug() << "Path incorrect : " + dir.absolutePath();
        setStatus(Broken);
    }
}

void    WatchPlaylist::_disabled()
{
//    if (QObject::receivers(SIGNAL(directoryChanged(QString))) > 0)
//        disconnect(m_watchfolder, SIGNAL(directoryChanged(QString)),
//                   this, SLOT(_refresh(QString)));
//    m_watchfolder->removePaths(m_watchfolder->directories());
}

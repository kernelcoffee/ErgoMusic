#include "watchplaylists.h"
#include "../Jobs/watchplaylistjob.h"
#include "coremanager.h"

#include <QUrl>
#include <QSqlQuery>
#include <QSqlError>

#include <QDebug>


WatchPlaylists::WatchPlaylists(QObject *parent) :
    QObject(parent)
{
    connect(this, &WatchPlaylists::watchPlaylistAdded,
            [=] { emit watchPlaylistsChanged(this); });
    connect(this, &WatchPlaylists::watchPlaylistRemoved,
            [=] { emit watchPlaylistsChanged(this); });
}

WatchPlaylists::~WatchPlaylists()
{

}

QList<WatchPlaylist *> WatchPlaylists::watchPlaylists() const
{
    return m_data;
}

WatchPlaylist *WatchPlaylists::at(int index) const
{
    return m_data.at(index);
}

// playlist added from action
void WatchPlaylists::addWatchPlaylist(QString &path)
{
    qDebug() << "add watch playlist : " << path;
    WatchPlaylist* playlist = new WatchPlaylist(path);
    m_data.append(playlist);
    _connectWatchPlaylist(m_data.count() - 1);
    playlist->refresh();

    emit watchPlaylistAdded(m_data.count() - 1);
}

// playlist added from DB
void WatchPlaylists::addWatchPlaylist(WatchPlaylist *playlist)
{
    m_data.append(playlist);
    _connectWatchPlaylist(m_data.count() - 1);
    playlist->refresh();
    emit watchPlaylistAdded(m_data.count() -1);
}

void WatchPlaylists::refreshWatchPlaylist(int index)
{
    m_data.at(index)->clear();
    m_data.at(index)->refresh();
}

void WatchPlaylists::removeWatchPlaylist(QString &path)
{
    for (int i = 0; i < m_data.size(); i++) {
        if (m_data.at(i)->path() == path)
            removeWatchPlaylist(i);
    }
}

void WatchPlaylists::removeWatchPlaylist(int index)
{
    qDebug() << "removing watchPlaylist : " << index;
    emit watchPlaylistRemoved(index);
    delete m_data.takeAt(index);
}

void WatchPlaylists::removeWatchPlaylist(WatchPlaylist *playlist)
{
    for (int i = 0; i < m_data.count(); i++)
        if (m_data.at(i) == playlist)
            removeWatchPlaylist(i);
}

bool WatchPlaylists::checkExistingPath(QString &path)
{
    for (auto playlist : m_data)
    {
        if (playlist->path() == path)
        {
            qDebug() << "Watchfolder already existing";
            return true;
        }
    }
    return false;
}

void WatchPlaylists::_connectWatchPlaylist(int index)
{
    WatchPlaylist* playlist = m_data.at(index);

    connect(playlist, &WatchPlaylist::requestRefresh,
            [=] { CoreManager::instance()->threads()->AddJob(new WatchPlaylistJob(playlist)); });
    connect(playlist, &WatchPlaylist::updated,
            [=] { emit watchPlaylistUpdated(index);});
    connect(playlist, &WatchPlaylist::statusChanged,
            [=] { emit watchPlaylistUpdated(index);});
}

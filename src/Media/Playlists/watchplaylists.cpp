#include "watchplaylists.h"
#include "../Jobs/watchplaylistjob.h"
#include "coremanager.h"
#include <QUrl>

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

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
void WatchPlaylists::addWatchPlaylist(QString path)
{
    WatchPlaylist* playlist = new WatchPlaylist(QUrl(path).toLocalFile());
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
    qDebug() << index;
    m_data.at(index)->clear();
    m_data.at(index)->refresh();
}

void WatchPlaylists::removeWatchPlaylist(int index)
{
    qDebug() << "removing watchPlaylist : " << index;
    emit watchPlaylistRemoved(index);
    delete m_data.takeAt(index);
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

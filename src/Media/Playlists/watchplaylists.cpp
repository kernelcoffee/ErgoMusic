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
    emit watchPlaylistAdded(addWatchPlaylist(new WatchPlaylist(path)));
}

// playlist added from DB
int WatchPlaylists::addWatchPlaylist(WatchPlaylist *playlist)
{
    m_data.append(playlist);
    _connectWatchPlaylist(m_data.count() - 1);
    playlist->refresh();
    return m_data.count() - 1;
}

void WatchPlaylists::refreshWatchPlaylist(int index)
{
    m_data.at(index)->clear();
    m_data.at(index)->refresh();
}

void WatchPlaylists::removeWatchPlaylist(QString &path)
{
    for (auto playlist : m_data)
        if (playlist->path() == path)
            removeWatchPlaylist(playlist);
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
    {
        if (m_data.at(i) == playlist)
            removeWatchPlaylist(i);
    }
}

bool WatchPlaylists::checkExistingPath(const QString &path)
{
    for (auto playlist : m_data) {
        if (playlist->path() == path) {
            qDebug() << "Watchfolder already exists";
            return true;
        }
    }
    return false;
}

void WatchPlaylists::cleanDuplicates()
{
    for (int i = 0; i < m_data.size(); ++i) {
        for (int n = m_data.size() -1; n > 0; --n) {
            if (m_data.at(i)->path() == m_data.at(n)->path()) {
                removeWatchPlaylist(n);
            }
        }
    }
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

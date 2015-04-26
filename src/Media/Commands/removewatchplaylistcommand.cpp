#include "removewatchplaylistcommand.h"
#include <QDebug>

RemoveWatchPlaylistCommand::RemoveWatchPlaylistCommand(WatchPlaylists *watchPlaylists, WatchPlaylist *playlist) :
    m_watchPlaylists(watchPlaylists)
  , m_playlist(playlist)
  , m_path(playlist->path())
{
}

void RemoveWatchPlaylistCommand::undo()
{
    qDebug() << "undo remove watchPlaylist command : " << m_path;
    m_watchPlaylists->addWatchPlaylist(m_path);
}

void RemoveWatchPlaylistCommand::redo()
{
    qDebug() << "remove watchplaylist command";
    m_watchPlaylists->removeWatchPlaylist(m_playlist);
}

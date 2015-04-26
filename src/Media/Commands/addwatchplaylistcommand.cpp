#include "addwatchplaylistcommand.h"
#include <QUrl>
#include <QDebug>

AddWatchPlaylistCommand::AddWatchPlaylistCommand(WatchPlaylists *watchPlaylists, QString path) :
    m_watchPlaylist(watchPlaylists)
  , m_path(QUrl(path).toLocalFile())
{

}

void AddWatchPlaylistCommand::undo()
{
    qDebug() << "undo watchPlaylist" << m_path;
    m_watchPlaylist->removeWatchPlaylist(m_path);
}

void AddWatchPlaylistCommand::redo()
{
    qDebug() << "new command add watchplaylist";
    if (!m_watchPlaylist->checkExistingPath(m_path))
        m_watchPlaylist->addWatchPlaylist(m_path);
    else
        qWarning() << QObject::tr("Path already in watchplaylists");
}


#ifndef REMOVEWATCHPLAYLISTCOMMAND_H
#define REMOVEWATCHPLAYLISTCOMMAND_H

#include <QUndoCommand>
#include "Media/Playlists/watchplaylists.h"

class RemoveWatchPlaylistCommand : public QUndoCommand
{
public:
    RemoveWatchPlaylistCommand(WatchPlaylists *watchPlaylists, WatchPlaylist *playlist);
    void undo();
    void redo();
private:
    WatchPlaylists *m_watchPlaylists;
    WatchPlaylist  *m_playlist;
    QString         m_path;
};

#endif // REMOVEWATCHPLAYLISTCOMMAND_H

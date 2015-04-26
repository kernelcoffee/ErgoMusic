#ifndef ADDWATCHPLAYLISTCOMMAND_H
#define ADDWATCHPLAYLISTCOMMAND_H

#include <QUndoCommand>
#include "Media/Playlists/watchplaylists.h"

class AddWatchPlaylistCommand : public QUndoCommand
{
public:
    AddWatchPlaylistCommand(WatchPlaylists *watchPlaylists, QString path);
    void undo();
    void redo();
private:
    WatchPlaylists *m_watchPlaylist;
    QString         m_path;
};

#endif // ADDWATCHPLAYLISTCOMMAND_H

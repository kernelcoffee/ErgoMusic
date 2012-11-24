#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "track.h"
#include <QMap>
#include <QList>

class Playlist
{
public:
    Playlist();
    ~Playlist();

    void    addTrack(Track*);
private:
    QList<Track*>    *m_list;
};

#endif // PLAYLIST_H

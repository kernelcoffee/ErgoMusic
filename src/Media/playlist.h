#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "track.h"
#include <QMap>
#include <QList>

class Track;

class Playlist
{
public:
    Playlist();
    Playlist(QString);
    ~Playlist();

    void    addTrack(Track*);
private:
    QString         m_name;
    QList<Track*>   *m_list;
};

#endif // PLAYLIST_H

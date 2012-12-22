#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "track.h"

class Track;

class Playlist
{
public:
    Playlist(QObject* parent = 0);
    Playlist(QString, QObject* parent = 0);
    ~Playlist();

    void    addTrack(Track*);
private:
    QString         m_name;
};

#endif // PLAYLIST_H

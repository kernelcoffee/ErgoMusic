#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "track.h"
#include "Utilities/Abstract/abstractplaylist.h"


class Playlist : public AbstractPlaylist
{
    Q_OBJECT
public:
    explicit Playlist(QObject *parent = 0);
    ~Playlist();
signals:
    
public slots:

};

#endif // PLAYLIST_H

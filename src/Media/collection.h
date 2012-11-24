#ifndef COLLECTION_H
#define COLLECTION_H

#include <QVector>
#include <QMap>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "playlist.h"


class Collection
{
public:
    Collection();
    ~Collection();
protected:
    QMap<int, Track*>   *m_tracks;
    QMap<int, Artist*>  *m_artists;
    QMap<int, Album*>   *m_albums;

    QVector<Playlist*>  *m_playlists;
};

#endif // COLLECTION_H

#ifndef COLLECTION_H
#define COLLECTION_H

#include <QVector>
#include <QMap>

#include "track.h"
#include "album.h"
#include "artist.h"

class Collection
{
public:
    Collection();
protected:
    QMap<int, Track*>   *m_tracks;
    QMap<int, Artist*>  *m_artists;
    QMap<int, Album*>   *m_albums;
};

#endif // COLLECTION_H

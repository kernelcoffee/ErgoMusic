#ifndef COLLECTION_H
#define COLLECTION_H

#include <QVector>
#include <QMap>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "playlist.h"
#include "watchplaylist.h"

class Collection
{
public:
    Collection();
    ~Collection();
    void                createPlaylist(QString &name = "");
protected:
    QMap<int, Track*>   *m_tracks;
    QMap<int, Artist*>  *m_artists;
    QMap<int, Album*>   *m_albums;

    QVector<Playlist*>  *m_playlists;
    WatchPlaylist       *m_watchPlaylist;
};

#endif // COLLECTION_H

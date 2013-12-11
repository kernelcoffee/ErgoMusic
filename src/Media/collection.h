#ifndef COLLECTION_H
#define COLLECTION_H

#include <QList>
#include <QHash>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "genre.h"

#include "Models/watchplaylistsmodel.h"

// Collection is a storage point for Artist / Album / Genre and tracks
// but is not necessarely saved in the database
// It can be used for a library or a watchfolder before import

class Genre;
class Artist;
class Album;

class Collection
{
public:
    Collection();
    ~Collection();
    void                init(QStringList&);

    QList<Track*>*       getTracks(void) const;
    Artist*             getArtist(QString) const;
    Album*              getAlbum(QString, Artist*) const;
    Genre*              getGenre(QString) const;

protected:
    QList<Track*>            *m_tracks;
    QHash<QString, Artist*>  *m_artists;
    QHash<QString, Album*>   *m_albums;
    QHash<QString, Genre*>   *m_genres;
};

#endif // COLLECTION_H

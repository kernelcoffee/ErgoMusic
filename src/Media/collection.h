#ifndef COLLECTION_H
#define COLLECTION_H

#include <QObject>
#include <QList>
#include <QMap>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "genre.h"

// Collection is a storage point for Artist / Album / Genre and tracks
// but is not necessarely saved in the database
// It can be used for a library or a watchfolder before import

class Genre;
class Artist;
class Album;
class Track;

class Collection : public QObject
{
    Q_OBJECT
public:
    explicit Collection(QObject* parent = 0);
    ~Collection();
    void                init(QStringList&);
    void                reset(void);

    QList<Track*>*      getTracks(void) const;
    Artist*             getArtist(QString) const;
    Album*              getAlbum(QString, Artist*) const;
    Genre*              getGenre(QString) const;

    void                addTrack(Track*);

signals:
    void                tracksUpdated();
public slots:

protected:
    QList<Track*>            *m_tracks;
    QMap<QString, Artist*>   *m_artists;
    QMap<QString, Album*>    *m_albums;
    QMap<QString, Genre*>    *m_genres;
};

#endif // COLLECTION_H

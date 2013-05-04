#ifndef COLLECTION_H
#define COLLECTION_H

#include <QList>
#include <QHash>
#include <QSplashScreen>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "genre.h"
#include "library.h"
#include "playlist.h"
#include "watchplaylist.h"

#include "Utilities/singleton.h"

class Genre;
class Artist;
class Album;
class Playlist;
class WatchPlaylist;

class Collection : public Singleton<Collection>
{
    friend class Singleton<Collection>;
public:
    Collection();
    ~Collection();
    void                init(QStringList&, QSplashScreen*);

    Artist*             getArtist(QString);
    Album*              getAlbum(QString, Artist*);
    Genre*              getGenre(QString);

    Library*            getLibrary();
    WatchPlaylist*      getWatchPlaylist() const;

    void                createPlaylist(QString name = "");
public slots:
protected:
    QList<Track*>            *m_tracks;
    QHash<QString, Artist*>  *m_artists;
    QHash<QString, Album*>   *m_albums;
    QHash<QString, Genre*>   *m_genres;

    Library             *m_library;
    QVector<Playlist*>  *m_playlists;
    WatchPlaylist       *m_watchPlaylist;
};

#endif // COLLECTION_H

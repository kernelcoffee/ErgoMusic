#ifndef COLLECTION_H
#define COLLECTION_H

#include <QVector>
#include <QHash>
#include <QSplashScreen>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "genre.h"
#include "playlist.h"
#include "watchplaylist.h"

#include "Utilities/singleton.h"

class Genre;

class Collection : public Singleton<Collection>
{
    friend class Singleton<Collection>;
public:
    Collection();
    ~Collection();
    void                init(QStringList&, QSplashScreen*);

    Artist*             getArtist(QString&);
    Album*              getAlbum(QString, Artist*);
    Genre*              getGenre(QString&);

    WatchPlaylist*      getWatchPlaylist() const;

    void                createPlaylist(QString name = "");
public slots:
protected:
    QVector<Track*>          *m_tracks;
    QHash<QString, Artist*>  *m_artists;
    QHash<QString, Album*>   *m_albums;
    QHash<QString, Genre*>   *m_genres;

    QVector<Playlist*>  *m_playlists;
    WatchPlaylist       *m_watchPlaylist;
};

#endif // COLLECTION_H

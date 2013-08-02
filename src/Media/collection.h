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

#include "Models/watchplaylistsmodel.h"

#include "Utilities/singleton.h"

class Genre;
class Artist;
class Album;
class Playlist;
class WatchPlaylist;
class WatchPlaylistsModel;

class Collection : public Singleton<Collection>
{
    friend class Singleton<Collection>;
public:
    Collection();
    ~Collection();
    void                init(QStringList&);

    Artist*             getArtist(QString);
    Album*              getAlbum(QString, Artist*);
    Genre*              getGenre(QString);

    Library*                  getLibrary();
    WatchPlaylistsModel*      getWatchPlaylists() const;

    void                createPlaylist(QString name = "");
    void                createWatchPlaylist(QString name, QString path);

    void                initDummyData(void);
public slots:
protected:
    QList<Track*>            *m_tracks;
    QHash<QString, Artist*>  *m_artists;
    QHash<QString, Album*>   *m_albums;
    QHash<QString, Genre*>   *m_genres;

    Library                 *m_library;
    QVector<Playlist*>      *m_playlists;
    WatchPlaylistsModel     *m_watchPlaylists;
};

#endif // COLLECTION_H

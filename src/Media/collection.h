#ifndef COLLECTION_H
#define COLLECTION_H

#include <QVector>
#include <QMap>
#include <QSplashScreen>

#include "track.h"
#include "album.h"
#include "artist.h"
#include "playlist.h"
#include "watchplaylist.h"

#include "Utilities/singleton.h"

class Collection : public Singleton<Collection>
{
    friend class Singleton<Collection>;
public:
    Collection();
    ~Collection();
    void                init(QStringList&, QSplashScreen*);

    WatchPlaylist*      getWatchPlaylist() const;

    void                createPlaylist(QString name = "");
public slots:
protected:
    QMap<int, Track*>   *m_tracks;
    QMap<int, Artist*>  *m_artists;
    QMap<int, Album*>   *m_albums;

    QVector<Playlist*>  *m_playlists;
    WatchPlaylist       *m_watchPlaylist;
};

#endif // COLLECTION_H

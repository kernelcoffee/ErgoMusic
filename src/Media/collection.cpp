#include "collection.h"
#include "Utilities/logger.h"
#include "coremanager.h"

Collection::Collection()
{
    Logger::log("Create collection instance", LOG_DEBUG);

    m_artists = new QHash<QString, Artist*>;
    m_albums = new QHash<QString, Album*>;
    m_genres = new QHash<QString, Genre*>;
    m_tracks = new QList<Track*>;
    m_library = new Library(m_tracks);
    m_playlists = new QVector<Playlist*>;
    m_watchPlaylists = new WatchPlaylistsModel;
}


Collection::~Collection()
{
    delete m_artists;
    delete m_albums;
    delete m_genres;
    delete m_tracks;
    delete m_library;
    delete m_watchPlaylists;
}

void Collection::init(QStringList &arguments)
{
    Q_UNUSED(arguments);

    Logger::log("Collection - Initialization", LOG_DEBUG);
    initDummyData();
//    DatabaseManager* dbmanager = CoreManager::instance()->database();
}

Artist* Collection::getArtist(QString artistName)
{
    while (m_artists->contains(artistName) == false)
        m_artists->insert(artistName, new Artist(artistName));
    return m_artists->value(artistName);
}

Album*  Collection::getAlbum(QString albumName, Artist *artist)
{
    if (m_albums->contains(albumName) == false ||
        m_albums->value(albumName)->albumArtist() != artist)
        m_albums->insert(albumName,new Album(albumName, artist));
    return m_albums->value(albumName);
}

Genre*  Collection::getGenre(QString name)
{
    if (m_genres->contains(name) == false)
        m_genres->insert(name, new Genre(name));
    return m_genres->value(name);
}

Library *Collection::getLibrary()
{
    return m_library;
}

WatchPlaylistsModel*  Collection::getWatchPlaylists() const
{
    return m_watchPlaylists;
}

void Collection::createPlaylist(QString name)
{
//    m_playlists->append(new Playlist(name));
}


void Collection::createWatchPlaylist(QString name, QString path)
{
//    m_watchPlaylists->append(new WatchPlaylist(name, path));
}


void Collection::initDummyData()
{
    m_watchPlaylists->addWatchPlaylist("test1", "/home/amoore/Dropbox/Music/watchFolder");
}

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
}


Collection::~Collection()
{
    delete m_artists;
    delete m_albums;
    delete m_genres;
    delete m_tracks;
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

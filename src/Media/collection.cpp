#include "collection.h"
#include "Utilities/logger.h"
#include "coremanager.h"

Collection::Collection(QObject *parent) :
    QObject(parent)
{
    Logger::log("Create collection instance", LOG_DEBUG);

    m_artists = new QMap<QString, Artist*>;
    m_albums = new QMap<QString, Album*>;
    m_genres = new QMap<QString, Genre*>;
    m_tracks = new QList<Track*>;
}

Collection::~Collection()
{
    delete m_artists;
    delete m_albums;
    delete m_genres;
    delete m_tracks;
}

void Collection::reset()
{
     QMap<QString, Artist*>::const_iterator a = m_artists->constBegin();
     while(a != m_artists->constEnd())
     {
         if (a.value())
            delete a.value();
     }
}

QList<Track *>* Collection::getTracks() const
{
    return m_tracks;
}

Artist* Collection::getArtist(QString artistName) const
{
    while (m_artists->contains(artistName) == false)
        m_artists->insert(artistName, new Artist(artistName));
    return m_artists->value(artistName);
}

Album*  Collection::getAlbum(QString albumName, Artist *artist) const
{
    if (m_albums->contains(albumName) == false ||
            m_albums->value(albumName)->albumArtist() != artist)
        m_albums->insert(albumName,new Album(albumName, artist));
    return m_albums->value(albumName);
}

Genre*  Collection::getGenre(QString name) const
{
    if (m_genres->contains(name) == false)
        m_genres->insert(name, new Genre(name));
    return m_genres->value(name);
}

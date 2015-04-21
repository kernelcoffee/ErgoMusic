#include "track.h"

Track::Track( QObject *parent) :
    QObject(parent)
{

}

Track::~Track()
{
}

QString Track::title() const
{
    return m_title;
}

QString Track::artist() const
{
    return m_artist;
}

QString Track::album() const
{
    return m_album;
}

QString Track::filePath() const
{
    return m_filePath;
}

void Track::setTitle(QString title)
{
    if (m_title == title)
        return;
    m_title = title;
    emit titleChanged(m_title);
}

void Track::setArtist(QString artist)
{
    if (m_artist == artist)
        return;
    m_artist = artist;
    emit artistChanged(artist);
}

void Track::setAlbum(QString album)
{
    if (m_album == album)
        return;
    m_album = album;
    emit albumChanged(album);
}

void Track::setPath(QString path)
{
    if (m_filePath == path)
        return;
    m_filePath = path;
    emit filePathChanged(path);
}



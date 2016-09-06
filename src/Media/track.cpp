#include "track.h"

Track::Track( QObject *parent) :
    QObject(parent)
{

}

Track::Track(QString path, QObject *parent) :
    QObject(parent)
  , m_filePath(path)
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

int Track::year() const
{
    return m_year;
}

int Track::track() const
{
    return m_track;
}

QString Track::genre() const
{
    return m_genre;
}

int Track::length() const
{
    return m_length;
}

QString Track::lengthAsFormatedString() const
{
    QString res;
    int duration = m_length;
    int seconds = (int) (duration % 60);
    duration /= 60;
    int minutes = (int) (duration % 60);
    duration /= 60;
    int hours = (int) (duration % 24);
    if(hours == 0)
        return res.sprintf("%02d:%02d", minutes, seconds);
    return res.sprintf("%02d:%02d:%02d", hours, minutes, seconds);
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

void Track::setYear(int year)
{
    if (m_year == year)
        return;
    m_year = year;
    emit yearChanged(year);
}

void Track::setTrack(int track)
{
    if (m_track == track)
        return;
    m_track = track;
    emit trackChanged(track);
}

void Track::setGenre(QString genre)
{
    if (m_genre == genre)
        return;
    emit genreChanged(genre);
}

void Track::setLength(int length)
{
    if (m_length == length)
        return;
    m_length = length;
    emit lengthChanged(length);
}

void Track::setPath(QString path)
{
    if (m_filePath == path)
        return;
    m_filePath = path;
    emit filePathChanged(path);
}



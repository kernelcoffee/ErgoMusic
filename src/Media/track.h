#ifndef TRACK_H
#define TRACK_H

#include "artist.h"
#include "album.h"
#include "genre.h"

#include <QFileInfo>

class Artist;
class Album;
class Genre;

class Track
{
public:
    Track();
    Track(QString);
    ~Track();

    int         uid();
    QString     title();
    Artist*     artist();
    Album*      album();

    void        setUid(int);
    void        setTitle(QString);
    void        setArtist(QString);
    void        setArtist(Artist*);
    void        setAlbum(QString);
    void        setAlbum(Album*);
private:
    void        _extractTags();
    void        _debugTags();
    Album       *m_album;
    Artist      *m_artist;
    Genre       *m_genre;

    QString     m_title;
    QFileInfo   *m_file;

    int         m_uid, m_duration, m_track, m_year, m_bitrate, m_sampleRate, m_channels;
};

#endif // TRACK_H

#ifndef TRACK_H
#define TRACK_H

#include "artist.h"
#include "album.h"

#include <QFileInfo>

class Artist;
class Album;

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
    Album       *m_album;
    Artist      *m_artist;

    QString     m_title;
    QFileInfo   *m_file;

    int         m_uid, m_duration, m_track;
};

#endif // TRACK_H

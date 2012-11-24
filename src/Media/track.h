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
    Track(QString path);

    int         getUid();
    QString     getTitle();
    Artist*     getArtist();

    void        setUid(int);
    void        setTitle(QString);
    void        setArtist(QString);
private:
    Album       *m_album;
    Artist      *m_artiste;

    QString     *m_title;
    QFileInfo   *m_file;

    int         uid, m_duration, m_track;
};

#endif // TRACK_H

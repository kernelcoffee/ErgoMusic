#ifndef ALBUM_H
#define ALBUM_H

#include "track.h"
#include "artist.h"

#include <QVector>
#include <QImage>

class Artist;
class Track;

class Album
{
public:
    Album();
private:
    QVector<Track*> *m_tracks;

    Artist          *m_albumArtist;

    QImage          *m_illustration;

    int             uid, m_year, m_disk, m_diskTotal;
    QString         *m_title, *m_description;
};

#endif // ALBUM_H

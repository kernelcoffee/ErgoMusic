#ifndef ALBUM_H
#define ALBUM_H

#include "track.h"
#include "artist.h"

#include <QVector>
#include <QImage>

class Album
{
public:
    Album();
private:
    QVector<Track*> *m_tracks;

    Artist          *m_albumArtist;

    QImage          *m_illustration;

    int             m_year;
};

#endif // ALBUM_H

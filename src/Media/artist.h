#ifndef ARTIST_H
#define ARTIST_H

#include "album.h"

#include <QVector>

class Artist
{
public:
    Artist();
private:
    Qvector<Album*> m_album;
};

#endif // ARTIST_H

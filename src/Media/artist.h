#ifndef ARTIST_H
#define ARTIST_H

#include "album.h"

#include <QList>
#include <QImage>

class Album;

class Artist
{
public:
    Artist();
    Artist(QString);
    ~Artist();

    QString    name();
    void       setName(QString);
private:
    QList<Album*> *m_albums;

    int             uid;
    QString         m_name, m_bio;
};

#endif // ARTIST_H

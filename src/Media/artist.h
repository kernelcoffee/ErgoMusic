#ifndef ARTIST_H
#define ARTIST_H

#include "album.h"

#include <QVector>
#include <QImage>

class Album;

class Artist
{
public:
    Artist();
    Artist(QString);
    ~Artist();

    QString    name();
    void    setName(QString);
private:
    QVector<Album*> *m_album;

    int             uid;
    QString         m_name, m_bio;
};

#endif // ARTIST_H

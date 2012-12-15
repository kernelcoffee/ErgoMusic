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
    Album(QString, Artist*);
    ~Album();

    QImage* illustration() const;
    QString name() const;
    QString description() const;
    Artist* albumArtist() const;

    int     uid() const;
    int     year() const;
    int     disk() const;
    int     diskTotal() const;

    QVector<Track*> tracks() const;

    void    setIllustration(QImage*);
    void    setTitle(QString&);
    void    setAlbumArtist(QString&);
    void    setDescription(QString&);
    void    setUid(int);
    void    setYear(int);
    void    setDisk(int);
    void    setDiskTotal(int);

private:
    QVector<Track*> *m_tracks;

    Artist          *m_albumArtist;

    QImage          *m_illustration;

    int             m_uid, m_year, m_disk, m_diskTotal;
    QString         m_name, *m_description;
};

#endif // ALBUM_H

#ifndef TRACK_H
#define TRACK_H

#include "collection.h"

#include <QFileInfo>
#include <QUrl>
#include <QMediaContent>
#include <QHash>

class Artist;
class Album;
class Genre;
class Collection;

class Track : public QMediaContent
{
public:
    Track(QUrl);
    ~Track();

    int         uid();
    QString     title();
    Artist*     artist();
    Album*      album();

    void        extractTags(void);
    void        extractTags(Collection*);
    QString     getValue(QString) const;
    QFileInfo   *getFile(void) const;

    void        setUid(int);
    void        setTitle(QString);
    void        setArtist(QString);
    void        setArtist(Artist*);
    void        setAlbum(QString);
    void        setAlbum(Album*);
    void        setYear(int);
    void        setGenre(Genre*);
    void        setGenre(QString);
    void        setTrack(int);
private:
    void        _setValue(QString, QString);
    void        _setValue(QString, int);

    void        _debugTags();
    Album       *m_album;
    Artist      *m_artist;
    Genre       *m_genre;

    QString     m_title;
    QFileInfo   *m_file;

    QHash<QString, QString>       m_data;

    int         m_uid, m_duration, m_track, m_year, m_bitrate, m_sampleRate, m_channels;
};

#endif // TRACK_H

#ifndef TRACK_H
#define TRACK_H

#include <QObject>

class Track : public QObject
{
    Q_OBJECT
public:
    explicit Track(QObject *parent = 0);
    explicit Track(QString path, QObject *parent = 0);

    QString title() const;
    QString artist() const;
    QString album() const;
    int     year() const;
    int     track() const;
    QString genre() const;
    int     length() const;

    QString filePath() const;

signals:
    void    titleChanged(QString title);
    void    artistChanged(QString artist);
    void    albumChanged(QString album);
    void    yearChanged(int year);
    void    trackChanged(int track);
    void    genreChanged(QString genre);
    void    lengthChanged(int length);

    void    filePathChanged(QString filePath);

public slots:
    void    setTitle(QString title);
    void    setArtist(QString artist);
    void    setAlbum(QString album);
    void    setYear(int year);
    void    setTrack(int track);
    void    setGenre(QString genre);
    void    setLength(int length);
    void    setPath(QString path);

private:
    QString m_title = "";
    QString m_artist = "";
    QString m_album = "";
    int     m_year = -1;
    int     m_track = -1;
    QString m_genre = "";
    int     m_length = -1;

    QString m_filePath = "";
};

#endif // TRACK_H

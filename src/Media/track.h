#ifndef TRACK_H
#define TRACK_H

#include <QObject>

class Track : public QObject
{
    Q_OBJECT
public:
    explicit Track(QObject *parent = 0);
    ~Track();

    QString title() const;
    QString artist() const;
    QString album() const;

    QString filePath() const;

signals:
    void    titleChanged(QString title);
    void    artistChanged(QString artist);
    void    albumChanged(QString album);

    void    filePathChanged(QString filePath);

public slots:
    void    setTitle(QString title);
    void    setArtist(QString artist);
    void    setAlbum(QString album);
    void    setPath(QString path);

private:
    QString m_title;
    QString m_artist;
    QString m_album;

    QString m_filePath;
};

#endif // TRACK_H

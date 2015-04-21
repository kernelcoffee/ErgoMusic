#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include "Media/mediacore.h"
#include "Ui/Media/Models/watchplaylistsmenumodel.h"

class MediaController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int contextIndex READ contextIndex WRITE setContextIndex NOTIFY contextIndexChanged)

public:
    explicit MediaController(QObject *parent = 0);
    ~MediaController();

    Q_INVOKABLE void    addWatchPlaylist(QString path);
    Q_INVOKABLE void    refreshWatchPlaylist(int index);
    Q_INVOKABLE void    removeWathPlaylist(int index);
    Q_INVOKABLE WatchPlaylistsMenuModel& watchPlaylistsModel();

    int contextIndex() const;

signals:
    void contextIndexChanged(int arg);

public slots:
    void setContextIndex(int arg);

private:
    MediaCore   *m_media;
    WatchPlaylistsMenuModel m_watchPlaytlistsModel;
    int m_contextIndex;
};

#endif // MEDIACONTROLLER_H

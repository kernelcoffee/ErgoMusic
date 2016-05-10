#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include "Media/mediacore.h"
#include "Ui/Media/Models/watchplaylistsmenumodel.h"

class MediaController : public QObject
{
    Q_OBJECT

public:
    explicit MediaController(QObject *parent = 0);
    ~MediaController();

    Q_INVOKABLE void    addWatchPlaylist(QString path);
    Q_INVOKABLE void    refreshWatchPlaylist(int index);
    Q_INVOKABLE void    removeWathPlaylist(int index);
    Q_INVOKABLE WatchPlaylistsMenuModel& watchPlaylistsModel();

private:
    MediaCore   *m_media;
    WatchPlaylistsMenuModel m_watchPlaytlistsModel;
};

#endif // MEDIACONTROLLER_H

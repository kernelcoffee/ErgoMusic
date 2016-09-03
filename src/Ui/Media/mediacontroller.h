#ifndef MEDIACONTROLLER_H
#define MEDIACONTROLLER_H

#include "Media/mediacore.h"
#include "Ui/Media/Models/watchplaylistsmodel.h"

class MediaController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(WatchPlaylistsModel* watchPlaylistsModel READ watchPlaylistsModel CONSTANT)

public:
    explicit MediaController(QObject *parent = 0);
    ~MediaController();

    Q_INVOKABLE void addWatchPlaylist(QString path);
    Q_INVOKABLE void refreshWatchPlaylist(int index);
    Q_INVOKABLE void removeWathPlaylist(int index);

    WatchPlaylistsModel* watchPlaylistsModel() const;

private:
    MediaCore *m_media;
    WatchPlaylistsModel* m_watchPlaytlistsModel;
};

#endif // MEDIACONTROLLER_H

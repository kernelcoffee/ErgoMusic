#ifndef WATCHPLAYLISTS_H
#define WATCHPLAYLISTS_H

#include <QObject>
#include "watchplaylist.h"

class WatchPlaylists : public QObject
{
    Q_OBJECT
public:
    explicit WatchPlaylists(QObject *parent = 0);
    ~WatchPlaylists();

    QList<WatchPlaylist*>   watchPlaylists() const;
    WatchPlaylist*          at(int index) const;

    void    addWatchPlaylist(QString &path);
    void    addWatchPlaylist(WatchPlaylist* playlist);
    void    refreshWatchPlaylist(int index);
    void    removeWatchPlaylist(QString &path);
    void    removeWatchPlaylist(int index);
    void    removeWatchPlaylist(WatchPlaylist* playlist);

    bool    checkExistingPath(QString &path);
signals:
    void    watchPlaylistsChanged(WatchPlaylists* watchPlaylists);

    void    watchPlaylistUpdated(int index);
    void    watchPlaylistRemoved(int index);
    void    watchPlaylistAdded(int index);

public slots:

private:
    void    _connectWatchPlaylist(int index);

    QList<WatchPlaylist*>   m_data;
};

#endif // WATCHPLAYLISTS_H

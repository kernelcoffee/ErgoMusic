#ifndef WATCHPLAYLISTDBHANDLER_H
#define WATCHPLAYLISTDBHANDLER_H

#include <QObject>

class WatchPlaylist;

class WatchPlaylistDBHandler : public QObject
{
    Q_OBJECT
public:
    explicit WatchPlaylistDBHandler(QObject *parent = 0);
    ~WatchPlaylistDBHandler();

    void   loadAll();
signals:

public slots:
    void    save(WatchPlaylist* playlist);
    void    remove(WatchPlaylist* playlist);
    void    update(WatchPlaylist* playlist);
};

#endif // WATCHPLAYLISTDBHANDLER_H

#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include "track.h"

#include <QFileSystemWatcher>

class WatchPlaylist : public QFileSystemWatcher
{
    Q_OBJECT
public:
    explicit WatchPlaylist(QObject *parent = 0);
    ~WatchPlaylist();
signals:
    
public slots:
    void    updateWatchFolder();
private:
    void            update();
    void            setWatchFolder();
    QList<Track*>   *m_list;
};

#endif // WATCHPLAYLIST_H

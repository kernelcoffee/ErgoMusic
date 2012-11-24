#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include <QFileSystemWatcher>

class WatchPlaylist : public QFileSystemWatcher
{
    Q_OBJECT
public:
    explicit WatchPlaylist(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // WATCHPLAYLIST_H

#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include "track.h"

#include <QFileSystemWatcher>

class Track;

class WatchPlaylist : public QFileSystemWatcher
{
    Q_OBJECT
public:
    explicit WatchPlaylist(QObject *parent = 0);
    ~WatchPlaylist();
signals:
    void            refreshed();
public slots:
    void            update();
private slots:
    void            _refresh(QString);
private:
    void            _update();
    void            _disable();
    QList<Track*>   *m_list;
};

#endif // WATCHPLAYLIST_H

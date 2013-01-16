#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include "track.h"
#include "Utilities/Abstract/abstractplaylist.h"

#include <QFileSystemWatcher>

class Track;

class WatchPlaylist : public AbstractPlaylist
{
    Q_OBJECT
public:
    WatchPlaylist(QObject *parent = 0);
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
    QFileSystemWatcher*  m_watchfolder;
};

#endif // WATCHPLAYLIST_H

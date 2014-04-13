#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include "track.h"
#include "collection.h"
#include "Utilities/Abstract/abstractplaylist.h"

#include <QFileSystemWatcher>
#include <QDir>
#include <QMutex>

class Collection;

class WatchPlaylist : public AbstractPlaylist
{
    Q_OBJECT
public:
    WatchPlaylist(QString path, QObject *parent = 0);
    ~WatchPlaylist();

signals:

public slots:
    void                update();
private slots:
    void                _refresh(QString);
private:
    QDir                m_path;

    void                 _update();
    void                 _disable();
    QFileSystemWatcher*  m_watchfolder;
};

#endif // WATCHPLAYLIST_H

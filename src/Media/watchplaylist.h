#ifndef WATCHPLAYLIST_H
#define WATCHPLAYLIST_H

#include "track.h"
#include "collection.h"
#include "Utilities/Abstract/abstractplaylist.h"

#include <QFileSystemWatcher>
#include <QDir>
#include <QMutex>

class Track;
class Collection;

class WatchPlaylist : public AbstractPlaylist
{
    Q_OBJECT
public:
    WatchPlaylist(QString name, QString path, QObject *parent = 0);
    ~WatchPlaylist();

    QString         name(void) const;
signals:
public slots:
    void            update();
private slots:
    void            _refresh(QString);
private:
    QDir            m_path;

    void                 _update();
    void                 _disable();
    QFileSystemWatcher*  m_watchfolder;
    Collection*          m_collection;
};

#endif // WATCHPLAYLIST_H

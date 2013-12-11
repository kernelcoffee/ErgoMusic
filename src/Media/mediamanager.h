#ifndef MEDIAMANAGER_H
#define MEDIAMANAGER_H

#include <QObject>
#include <QList>

#include "collection.h"
#include "library.h"
#include "Models/watchplaylistsmodel.h"

class MediaManager : public QObject
{
    Q_OBJECT
public:
    explicit MediaManager(QObject *parent = 0);
    ~MediaManager();
    void                    init(QStringList&);

    void                    initDummyData(void);
    Library*                library(void) const;
    Collection*             getCollection(void) const;
    WatchPlaylistsModel*    getWatchPlaylists(void) const;
signals:

public slots:

private:
    Library*                m_library;
    Collection*             m_collection;
    WatchPlaylistsModel     *m_watchPlaylists;
};

#endif // MEDIAMANAGER_H

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

    void                    setCurrentModel(AbstractPlaylist*);

    AbstractPlaylist*       currentModel(void) const;

    Library*                library(void) const;
    Collection*             collection(void) const;
    WatchPlaylistsModel*    watchPlaylists(void) const;
signals:
    void    currentModelUpdated();
public slots:

private:
    Library*                m_library;
    Collection*             m_collection;
    WatchPlaylistsModel     *m_watchPlaylists;
    AbstractPlaylist*       m_currentModel;
};

#endif // MEDIAMANAGER_H

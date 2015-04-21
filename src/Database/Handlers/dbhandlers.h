#ifndef DBHANDLERS_H
#define DBHANDLERS_H

#include <QObject>
#include "watchplaylistdbhandler.h"

class DbHandlers : public QObject
{
    Q_OBJECT
public:
    explicit DbHandlers(QObject *parent = 0);
    ~DbHandlers();

    WatchPlaylistDBHandler*  WatchPlaylist();

    void    delayedInit();
signals:

public slots:

private:
    WatchPlaylistDBHandler  *m_watchPlaylist;
};

#endif // DBHANDLERS_H

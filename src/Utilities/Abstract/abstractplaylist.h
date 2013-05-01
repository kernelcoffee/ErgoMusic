#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

//#include "Media/track.h"

//#include <QMediaPlaylist>
#include <QObject>

class Track;

class AbstractPlaylist : public QObject
{
    Q_OBJECT
public:
    enum Type {INVALID, LIBRARY, WATCHPLAYLIST, PLAYLIST, DPLAYLIST};

    virtual ~AbstractPlaylist();
    virtual Type                getType(void) const;
    virtual QList<Track*>*      getList(void) const;
protected:
    AbstractPlaylist();
    AbstractPlaylist(QObject *parent = 0);

    QList<Track*>*   m_list;
    Type             m_type;

signals:
    void    updated();
};

#endif // ABSTRACTPLAYLIST_H

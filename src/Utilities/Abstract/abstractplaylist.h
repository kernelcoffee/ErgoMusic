#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

#include <QObject>
#include <QMutex>
#include <QList>
#include <QAbstractListModel>
#include "common.h"
#include "Media/collection.h"

class Track;

class AbstractPlaylist : public QObject
{
    Q_OBJECT
public:
    virtual ~AbstractPlaylist();


    virtual QString                 name(void) const;
    virtual Collection              *collection();
    virtual Track*                  at(int) const;
    virtual ViewType                type(void) const;
    virtual int                     size() const;
    virtual bool                    isLocked();

signals:
    void    updated();
protected:
    AbstractPlaylist(QObject *parent = 0);

    QString                 m_name;
    ViewType                m_type;
    QList<Track*>           m_list;
    QMutex                  m_mutex;
    Collection              *m_collection;
};

#endif // ABSTRACTPLAYLIST_H

#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

#include <QObject>
#include <QList>

#include "Media/track.h"

class AbstractPlaylist : public QObject
{
    Q_OBJECT
public:
    virtual ~AbstractPlaylist();

    virtual int             id() const;
    virtual QString         name() const;
    virtual QList<Track*>   tracks() const;
    virtual void            addTrack(Track*);
    virtual void            clear();

signals:
    void    updated();

public slots:

protected:
    explicit AbstractPlaylist(QObject *parent = 0);

    int             m_id;
    QString         m_name;
    QList<Track*>   m_tracks;
};

#endif // ABSTRACTPLAYLIST_H

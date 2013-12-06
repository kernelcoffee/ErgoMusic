#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

#include <QObject>
#include <QMutex>
#include <QList>

class Track;

class AbstractPlaylist : public QObject
{
    Q_OBJECT
public:
    enum Type {INVALID, LIBRARY, WATCHPLAYLIST, PLAYLIST, DPLAYLIST};

    virtual ~AbstractPlaylist();

    virtual void                    setViewType();

    virtual Type                    getType(void) const;
    virtual QList<Track*>*          getList(void) const;
    virtual bool                    isLocked(void);

protected:
    AbstractPlaylist();
    AbstractPlaylist(QObject *parent = 0);

    QString                 m_name;
    QList<Track*>*          m_list;
    Type                    m_type;
    QMutex                  m_mutex;

signals:
    void    updated();
};

#endif // ABSTRACTPLAYLIST_H

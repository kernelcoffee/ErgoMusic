#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

#include <QObject>
#include <QMutex>
#include <QList>
#include <QAbstractListModel>

class Track;

class AbstractPlaylist : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Type {INVALID, LIBRARY, WATCHPLAYLIST, PLAYLIST, DPLAYLIST};

    Q_PROPERTY(int count READ rowCount() NOTIFY countChanged())

    virtual ~AbstractPlaylist();

    virtual QVariant                data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    virtual int                     rowCount(const QModelIndex &index = QModelIndex()) const;
    virtual QHash<int, QByteArray>  roleNames() const;

//    virtual void                    setViewType();

    virtual Type                    getType(void) const;
    virtual QList<Track*>*          getList(void) const;
    virtual bool                    isLocked(void);

    virtual QString                 name(void) const;
signals:
    void        countChanged();

protected slots:
    virtual void        insert(int, const Track*) = 0;
    virtual void        append(const Track*) = 0;
    virtual void        remove(int) = 0;
    virtual QObject*    get(int) = 0; // retrieve an item
    virtual void        setProperty(int index, const QString& property, const QVariant& value) = 0;

protected:
    AbstractPlaylist();
    AbstractPlaylist(QObject *parent = 0);

    QString                 m_name;
    QList<Track*>*          m_list;
    Type                    m_type;
    QMutex                  m_mutex;

    QHash<int, QByteArray>       roles;

signals:
    void    updated();
};

#endif // ABSTRACTPLAYLIST_H

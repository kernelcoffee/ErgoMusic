#ifndef ABSTRACTPLAYLIST_H
#define ABSTRACTPLAYLIST_H

#include <QObject>
#include <QMutex>
#include <QList>
#include <QAbstractListModel>
#include "common.h"
#include "Media/collection.h"

class Track;

class AbstractPlaylist : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ rowCount() NOTIFY countChanged())
public:
    virtual ~AbstractPlaylist();

    virtual QVariant                data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    virtual int                     rowCount(const QModelIndex &index = QModelIndex()) const;
    virtual QHash<int, QByteArray>  roleNames() const;

    virtual ViewType                type(void) const;
    virtual bool                    isLocked(void);

    virtual QString                 name(void) const;
    Q_INVOKABLE virtual void        requestDisplay();
signals:
    void        countChanged();
    void        requestDisplay(AbstractPlaylist*);
protected slots:
    virtual void        select(int);
    virtual void        insert(int, const Track*) = 0;
    virtual void        append(const Track*) = 0;
    virtual void        remove(int) = 0;
    virtual QObject*    get(int) = 0; // retrieve an item
    virtual void        setProperty(int index, const QString& property, const QVariant& value) = 0;
protected:
    enum Roles {
        Index = Qt::UserRole,
        Title,
        Author
    };

    AbstractPlaylist();
    AbstractPlaylist(QObject *parent = 0);

    QString                 m_name;
    ViewType                m_type;
    QMutex                  m_mutex;
    Collection*             m_collection;

    QHash<int, QByteArray>  m_roles;

signals:
    void    updated();
};

#endif // ABSTRACTPLAYLIST_H

#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>
#include "Utilities/Abstract/abstractplaylist.h"

class PlaylistModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PlaylistModel(QObject *parent = 0);
    QVariant                data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    int                     rowCount(const QModelIndex &index = QModelIndex()) const;
    QHash<int, QByteArray>  roleNames() const;
    void                    setModel(AbstractPlaylist*);

signals:
    void        countChanged();
public slots:
    void        insert(int, const QString&);
    void        append(const QString&);
    void        remove(int);
    QObject*    get(int); // retrieve an item
    void        setProperty(int index, const QString& property, const QVariant& value);

public:
    enum Roles {
        Index = Qt::UserRole,
        Title,
        Author
    };
    QHash<int, QByteArray>  m_roles;
    AbstractPlaylist*       m_data;
};

#endif // PLAYLISTMODEL_H

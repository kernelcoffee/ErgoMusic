#ifndef WatchPlaylistsModel_H
#define WatchPlaylistsModel_H

#include <QAbstractListModel>
#include <QVector>
#include "Media/watchplaylist.h"

class WatchPlaylist;

class WatchPlaylistsModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        NameRole = Qt::UserRole
    };

    Q_PROPERTY(int count READ rowCount() NOTIFY countChanged())

    explicit WatchPlaylistsModel(QObject *parent = 0);
    QVariant                data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    int                     rowCount(const QModelIndex &index = QModelIndex()) const;
    QHash<int, QByteArray>  roleNames() const;

    void                    addWatchPlaylist(QString, QString);

signals:
    void        countChanged();

public slots:
    void        insert(int, const QString&);
    void        append(const QString&);
    void        remove(int);
    QObject*    get(int); // retrieve an item
    void        setProperty(int index, const QString& property, const QVariant& value);

private:
       QObject*                     m_parent;
       QVector<WatchPlaylist*>*     m_watchPlaylists;
       QHash<int, QByteArray>       roles;
};

#endif // WatchPlaylistsModel_H

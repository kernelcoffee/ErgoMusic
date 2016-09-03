#ifndef WATCHPLAYLISTSMODEL_H
#define WATCHPLAYLISTSMODEL_H

#include <QAbstractListModel>
#include "Media/Playlists/watchplaylists.h"

class WatchPlaylistsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        Name = Qt::UserRole,
        Status,
        Type
    };

    WatchPlaylistsModel(WatchPlaylists* watch, QObject *parent = 0);

    QVariant                data(const QModelIndex &index, int role) const override;
    int                     rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray>  roleNames() const override;

public slots:
    bool    removeRow(int row, const QModelIndex &parent = QModelIndex());

private:
    WatchPlaylists*  m_data;
};

#endif // WATCHPLAYLISTSMODEL_H

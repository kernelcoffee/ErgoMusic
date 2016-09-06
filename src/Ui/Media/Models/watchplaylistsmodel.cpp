#include "watchplaylistsmodel.h"
#include "Ui/uicommon.h"

#include <QDebug>

WatchPlaylistsModel::WatchPlaylistsModel(WatchPlaylists *watch, QObject *parent) :
    QAbstractListModel(parent)
  , m_data(watch)
{
    connect(m_data, &WatchPlaylists::watchPlaylistsChanged,
            [=] () { emit layoutChanged(); });
    connect(m_data, &WatchPlaylists::watchPlaylistRemoved,
            [=] (int index) { this->removeRow(index);});
    connect(m_data, &WatchPlaylists::watchPlaylistUpdated,
            [=] (int index) { emit dataChanged(this->index(index), this->index(index)); });
}

QVariant WatchPlaylistsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > rowCount())
        return QVariant();

    switch (role) {
    case Name:
        return m_data->at(index.row())->name();
    case Status:
        return m_data->at(index.row())->status();
    case Type:
        return (int)ModelType::WATCHPLAYLIST;
    default:
        return "invalid";
    }
    return QVariant();
}

int WatchPlaylistsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return m_data->watchPlaylists().count();
}

QHash<int, QByteArray> WatchPlaylistsModel::roleNames() const
{
    return {
        { Name, "name"},
        { Status, "status"},
        { Type, "type"}
    };
}

bool WatchPlaylistsModel::removeRow(int row, const QModelIndex &parent)
{
    Q_UNUSED(parent)
    beginRemoveRows(QModelIndex(), row, row);
    endRemoveRows();
    return true;
}


#include "watchplaylistsmodel.h"
#include <QHash>
#include <QByteArray>

#include "Utilities/logger.h"

WatchPlaylistsModel::WatchPlaylistsModel(QObject *parent) :
    QAbstractListModel(parent), m_parent(parent)
{
    Logger::log("Create WatchPlaylistModel", LOG_DEBUG);
    m_roles[NameRole] = "name";
    m_roles[TypeRole] = "type";

    m_watchPlaylists = new QVector<WatchPlaylist*>;
}

QVariant WatchPlaylistsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > rowCount())
        return QVariant();

    switch (role) {
    case NameRole:
        Logger::log("WatchPlaylistModel request name - " + m_watchPlaylists->at(index.row())->name(), LOG_DEBUG);
        return m_watchPlaylists->at(index.row())->name();
    case TypeRole:
        return m_watchPlaylists->at(index.row())->type();
    break;
        default:
            return "invalid";
    }
    return QVariant();
}

int WatchPlaylistsModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_watchPlaylists->count();
}

QHash<int, QByteArray> WatchPlaylistsModel::roleNames() const
{
    return m_roles;
}

void WatchPlaylistsModel::addWatchPlaylist(QString path)
{
    m_watchPlaylists->append(new WatchPlaylist(path));
}

WatchPlaylist *WatchPlaylistsModel::getWatchPlaylist(int index)
{
    return m_watchPlaylists->at(index);
}

void WatchPlaylistsModel::insert(int, const QString &)
{

}

void WatchPlaylistsModel::append(const QString &)
{

}

void WatchPlaylistsModel::remove(int)
{

}

QObject *WatchPlaylistsModel::get(int index)
{
    if (index < rowCount())
        return m_watchPlaylists->at(index);
    return NULL;
}

void WatchPlaylistsModel::setProperty(int index, const QString &property, const QVariant &value)
{

}

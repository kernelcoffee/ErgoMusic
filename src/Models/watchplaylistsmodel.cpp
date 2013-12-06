#include "watchplaylistsmodel.h"
#include <QHash>
#include <QByteArray>

#include "Utilities/logger.h"

WatchPlaylistsModel::WatchPlaylistsModel(QObject *parent) :
    QAbstractListModel(parent), m_parent(parent)
{
    Logger::log("Create WatchPlaylistModel", LOG_DEBUG);
    roles[NameRole] = "name";

    m_watchPlaylists = new QVector<WatchPlaylist*>;
}

QVariant WatchPlaylistsModel::data(const QModelIndex &index, int role) const
{
    Logger::log("WatchPlaylistModel - data", LOG_DEBUG);
    if (index.row() < 0 || index.row() > rowCount())
        return QVariant();

    switch (role) {
    case NameRole:
        Logger::log("date - " + m_watchPlaylists->at(index.row())->name(), LOG_DEBUG);
        return m_watchPlaylists->at(index.row())->name();
    break;
        default:
            return "toto";
    }
    return QVariant();
}

int WatchPlaylistsModel::rowCount(const QModelIndex &index) const
{
    return m_watchPlaylists->count();
}

QHash<int, QByteArray> WatchPlaylistsModel::roleNames() const
{
    return roles;
}

void WatchPlaylistsModel::addWatchPlaylist(QString name, QString path)
{
    m_watchPlaylists->append(new WatchPlaylist(name, path));
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

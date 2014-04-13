#include "playlistmodel.h"

PlaylistModel::PlaylistModel(QObject *parent) :
    QAbstractListModel(parent)
{
    m_roles[Index] = "index";
    m_roles[Title] = "title";
    m_roles[Author] = "author";
}

QVariant PlaylistModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > rowCount())
        return QVariant();

    Track*  track = m_data->at(index.row());

    switch (role) {
    case Index:
        return index.row();
    case Title:
        return track->title();
        break;
    case Author:
        return track->artist()->name();
        break;
    default:
        return "invalid";
    }
    return QVariant();

}

int PlaylistModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_data->size();
}

QHash<int, QByteArray> PlaylistModel::roleNames() const
{
    return m_roles;
}

void PlaylistModel::setModel(AbstractPlaylist *data)
{
    m_data = data;
}

void PlaylistModel::insert(int, const QString &)
{

}

void PlaylistModel::append(const QString &)
{

}

void PlaylistModel::remove(int)
{

}

QObject *PlaylistModel::get(int index)
{
    return m_data->at(index);
}

void PlaylistModel::setProperty(int index, const QString &property, const QVariant &value)
{

}

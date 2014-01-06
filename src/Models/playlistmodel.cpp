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

    Track*  track = m_model->at(index.row());

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
}

QHash<int, QByteArray> PlaylistModel::roleNames() const
{

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

QObject *PlaylistModel::get(int)
{

}

void PlaylistModel::setProperty(int index, const QString &property, const QVariant &value)
{

}

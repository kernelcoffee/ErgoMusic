#include "songsmodel.h"

SongsModel::SongsModel(QObject *parent) :
    QAbstractListModel(parent)
{

}

QVariant SongsModel::data(const QModelIndex &index, int role) const
{

}

int SongsModel::rowCount(const QModelIndex &index) const
{

}

QHash<int, QByteArray> SongsModel::roleNames() const
{

}

void SongsModel::insert(int, const QString &)
{

}

void SongsModel::append(const QString &)
{

}

void SongsModel::remove(int)
{

}

QObject *SongsModel::get(int)
{

}

void SongsModel::setProperty(int index, const QString &property, const QVariant &value)
{

}

#include "trackmodel.h"
#include "Media/track.h"

#include <QDebug>

TrackModel::TrackModel(QObject *parent) :
    QAbstractTableModel(parent)
  , m_data(nullptr)
{
    qRegisterMetaType<TrackModel*>("TrackModel");
}

TrackModel::~TrackModel()
{

}

QVariant TrackModel::data(const QModelIndex &index, int role) const
{
    if (m_data == nullptr || index.row() < 0 || index.row() > rowCount())
        return QVariant();

    qDebug() << index.row() << " " << index.column();
    Track*  track = m_data->tracks().at(index.row());

    switch (role) {
    case Index:
        return index.row() + 1;
    case Title:
        return track->title();
    case Artist:
        return track->artist();
    }
    return "Invalid";
}

QVariant TrackModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    qDebug() << "header data " << section << " " << orientation << " " << role;
    return QVariant();
}

int TrackModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if (m_data == nullptr)
        return 0;
    return m_data->tracks().count();
}

int TrackModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
//    qDebug() << "column count";
    return 4;
}

QHash<int, QByteArray> TrackModel::roleNames() const
{
    return {
        {Index, "index" },
        {Title, "title"},
        {Artist, "artist"},
        {Album, "album"}
    };
}

void TrackModel::setModel(AbstractPlaylist *model)
{
    beginResetModel();
    m_data = model;
    endResetModel();
}


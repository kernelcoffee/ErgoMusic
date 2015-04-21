#include "trackmodel.h"
#include "Media/track.h"

#include <QDebug>

TrackModel::TrackModel(QObject *parent) :
    QAbstractListModel(parent)
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

int TrackModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    if (m_data == nullptr)
        return 0;
    return m_data->tracks().count();
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
    qDebug() << "set new model " << model;
    beginResetModel();
    m_data = model;
    endResetModel();
}


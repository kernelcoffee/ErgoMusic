#include "tracksortmodel.h"
#include <QDebug>

TrackSortModel::TrackSortModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

void TrackSortModel::sort(int column, Qt::SortOrder order)
{
    qDebug("Sorting by column %d", column);
    QSortFilterProxyModel::sort(column, order);
}

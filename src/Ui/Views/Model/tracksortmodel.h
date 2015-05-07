#ifndef TRACKSORTMODEL_H
#define TRACKSORTMODEL_H

#include <QSortFilterProxyModel>

class TrackSortModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit TrackSortModel(QObject *parent = 0);

signals:

public slots:
    Q_INVOKABLE virtual void sort(int column, Qt::SortOrder order);
};

#endif // TRACKSORTMODEL_H

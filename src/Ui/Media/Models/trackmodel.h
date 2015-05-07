#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QAbstractTableModel>
#include "Media/Abstracts/abstractplaylist.h"

class TrackModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Roles {
        Index,
        Title,
        Artist,
        Album,
        Length,
        Genre,
        TrackPos,
        FilePath
    };

    explicit TrackModel(QObject *parent = 0);

    QVariant                data(const QModelIndex &index, int role) const override;
    QVariant                headerData(int section, Qt::Orientation orientation, int role) const;
    int                     rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int                     columnCount(const QModelIndex &parent) const override;
    QHash<int, QByteArray>  roleNames() const override;
signals:

public slots:
    void    setModel(AbstractPlaylist* model);
private:
    AbstractPlaylist*   m_data;
};

#endif // TRACKMODEL_H

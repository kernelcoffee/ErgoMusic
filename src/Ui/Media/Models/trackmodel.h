#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QAbstractListModel>
#include "Media/Abstracts/abstractplaylist.h"

class TrackModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        Index,
        Title,
        Artist,
        Album
    };
    explicit TrackModel(QObject *parent = 0);
    ~TrackModel();

    QVariant                data(const QModelIndex &index, int role) const override;
    int                     rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray>  roleNames() const override;
signals:

public slots:
    void    setModel(AbstractPlaylist* model);
private:
    AbstractPlaylist*   m_data;
};

#endif // TRACKMODEL_H

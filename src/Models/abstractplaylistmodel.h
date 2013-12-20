#ifndef ABSTRACTPLAYLISTMODEL_H
#define ABSTRACTPLAYLISTMODEL_H

#include <QAbstractListModel>

class AbstractPlaylistModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AbstractPlaylistModel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // ABSTRACTPLAYLISTMODEL_H

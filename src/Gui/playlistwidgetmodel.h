#ifndef PLAYLISTWIDGETMODEL_H
#define PLAYLISTWIDGETMODEL_H

#include <QStringList>

#include "Models/treemodel.h"
#include "playlistwidgetitem.h"

class PlaylistWidgetModel : public TreeModel
{
    Q_OBJECT
public:
    explicit PlaylistWidgetModel();
    QVariant    data(const QModelIndex&, int role) const;
signals:
    
public slots:

protected:
    void    setupModelData();
};

#endif // PLAYLISTWIDGETMODEL_H

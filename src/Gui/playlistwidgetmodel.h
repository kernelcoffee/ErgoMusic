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

signals:
    
public slots:

protected:
    void    setupModelData();
};

#endif // PLAYLISTWIDGETMODEL_H

#ifndef SIDEBARWIDGETMODEL_H
#define SIDEBARWIDGETMODEL_H

#include <QStringList>

#include "treemodel.h"
#include "Gui/Items/sidebarwidgetitem.h"

class SidebarWidgetModel : public TreeModel
{
    Q_OBJECT
public:
    explicit SidebarWidgetModel();

signals:
    
public slots:

protected:
    void    setupModelData();
};

#endif // SidebarWIDGETMODEL_H

#ifndef SIDEBARWIDGETITEM_H
#define SIDEBARWIDGETITEM_H

#include "treeitem.h"

class SidebarWidgetItem : public TreeItem
{
public:
    enum Type {INVALID, LIBRARY, WATCHPLAYLIST, PLAYLIST, DPLAYLIST};

    SidebarWidgetItem(const QString title, TreeItem* parent = 0);
    SidebarWidgetItem(const QString title, Type type = INVALID, TreeItem* parent = 0);
    SidebarWidgetItem(const QString title, Type type = INVALID, int index = 0, TreeItem* parent = 0);

    Type       getType(void) const;
    int        getIndex(void) const;
private:
    Type    m_type;
    int     m_index;
};

#endif // SidebarWIDGETITEM_H

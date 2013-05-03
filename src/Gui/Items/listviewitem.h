#ifndef LISTVIEWITEMS_H
#define LISTVIEWITEMS_H

#include "treeitem.h"
#include "Media/track.h"

class ListViewItem : public TreeItem
{
public:
    ListViewItem(Track*, TreeItem* parent = 0);
    QVariant    data(QString column) const;
private:
    Track*      m_track;
};

#endif // LISTVIEWITEMS_H

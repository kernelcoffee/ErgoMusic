#ifndef PLAYLISTWIDGETITEM_H
#define PLAYLISTWIDGETITEM_H

#include "Models/treeitem.h"

class PlaylistWidgetItem : public TreeItem
{
public:
    PlaylistWidgetItem(const QString title, TreeItem* parent = 0);
};

#endif // PLAYLISTWIDGETITEM_H

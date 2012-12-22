#ifndef PLAYLISTWIDGETITEM_H
#define PLAYLISTWIDGETITEM_H

#include "Models/treeitem.h"

class PlaylistWidgetItem : public TreeItem
{
public:
    enum Type {INVALID, LIBRARY, WATCHPLAYLIST, PLAYLIST, DPLAYLIST};

    PlaylistWidgetItem(const QString title, TreeItem* parent = 0);
    PlaylistWidgetItem(const QString title, Type type = INVALID, TreeItem* parent = 0);
    PlaylistWidgetItem(const QString title, Type type = INVALID, int index = 0, TreeItem* parent = 0);

    Type        getType(void) const;
    int        getIndex(void) const;
private:
    Type    m_type;
    int     m_index;
};

#endif // PLAYLISTWIDGETITEM_H

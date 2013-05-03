#include "listviewitem.h"

ListViewItem::ListViewItem(Track* track, TreeItem* parent) :
    TreeItem("track", parent)
{
    m_track = track;
}

QVariant ListViewItem::data(QString column) const
{
    return m_track->getValue(column);
}

#include "abstractplaylist.h"

AbstractPlaylist::AbstractPlaylist(QObject *parent) :
    QObject(parent)
{
}

AbstractPlaylist::~AbstractPlaylist()
{}

void AbstractPlaylist::setViewType(ViewWidget::ViewType type)
{
    m_viewType = type;
}

AbstractPlaylist::Type    AbstractPlaylist::getType(void) const
{
    return m_type;
}

QList<Track*>*  AbstractPlaylist::getList(void) const
{
    return m_list;
}

ViewWidget::ViewType AbstractPlaylist::getViewType() const
{
    return m_viewType;
}

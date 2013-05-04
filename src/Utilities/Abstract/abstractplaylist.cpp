#include "abstractplaylist.h"
#include "Utilities/logger.h"

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

bool AbstractPlaylist::isLocked()
{
    bool    ret = m_mutex.tryLock();;

    if (ret)
        m_mutex.unlock();
    return !ret;
}

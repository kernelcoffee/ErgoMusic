#include "abstractplaylist.h"
#include "Utilities/logger.h"

AbstractPlaylist::AbstractPlaylist(QObject *parent) :
    QAbstractListModel(parent)
{

}

AbstractPlaylist::~AbstractPlaylist()
{}

QVariant AbstractPlaylist::data(const QModelIndex &index, int role) const
{
    return "toto";
}

//void AbstractPlaylist::setViewType()
//{
//    m_viewType = type;
//}

int AbstractPlaylist::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    m_list->count();
}

QHash<int, QByteArray>  AbstractPlaylist::roleNames() const
{
    return roles;
}

AbstractPlaylist::Type    AbstractPlaylist::getType(void) const
{
    return m_type;
}

QList<Track*>*  AbstractPlaylist::getList(void) const
{
    return m_list;
}

//ViewWidget::ViewType AbstractPlaylist::getViewType() const
//{
//    return m_viewType;
//}

bool AbstractPlaylist::isLocked()
{
    bool    ret = m_mutex.tryLock();;

    if (ret)
        m_mutex.unlock();
    return !ret;
}

QString AbstractPlaylist::name() const
{
    return m_name;
}

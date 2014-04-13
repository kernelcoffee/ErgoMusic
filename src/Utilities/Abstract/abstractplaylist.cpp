#include "abstractplaylist.h"
#include "Utilities/logger.h"
#include "common.h"
#include <QDebug>
#include "coremanager.h"

AbstractPlaylist::AbstractPlaylist(QObject *parent) :
    QObject(parent)
  , m_name("")
  , m_type(INVALID)
  , m_list()
  , m_collection(NULL)
{}

AbstractPlaylist::~AbstractPlaylist()
{}


ViewType    AbstractPlaylist::type(void) const
{
    return m_type;
}

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

Collection *AbstractPlaylist::collection()
{
    return m_collection;
}

int AbstractPlaylist::size() const
{
    return m_list.size();
}

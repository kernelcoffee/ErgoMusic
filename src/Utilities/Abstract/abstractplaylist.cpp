#include "abstractplaylist.h"
#include "Utilities/logger.h"
#include "common.h"
#include <QDebug>

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

int AbstractPlaylist::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    qDebug() << "Abstract Playlist " << this <<  " rowCount " << m_collection->getTracks()->count();
    return m_collection->getTracks()->count();
}

QHash<int, QByteArray>  AbstractPlaylist::roleNames() const
{
    return roles;
}

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

void AbstractPlaylist::requestDisplay()
{
    Logger::log("AbstractPlaylist " + m_name + " emit requestDisplay Signal");
    emit requestDisplay(this);
}

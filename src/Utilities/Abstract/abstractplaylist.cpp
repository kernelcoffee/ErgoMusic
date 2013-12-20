#include "abstractplaylist.h"
#include "Utilities/logger.h"
#include "common.h"
#include <QDebug>

AbstractPlaylist::AbstractPlaylist(QObject *parent) :
    QAbstractListModel(parent)
{
    m_roles[Index] = "index";
    m_roles[Title] = "title";
    m_roles[Author] = "author";
}

AbstractPlaylist::~AbstractPlaylist()
{}

QVariant AbstractPlaylist::data(const QModelIndex &index, int role) const
{

    if (index.row() < 0 || index.row() > rowCount())
        return QVariant();

    switch (role) {
    case Index:
        return index.row();
    case Title:
        return m_collection->getTracks()->at(index.row())->title();
        break;
    case Author:
        return m_collection->getTracks()->at(index.row())->artist()->name();
        break;
    default:
        return "invalid";
    }
    return QVariant();
}

int AbstractPlaylist::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);
    return m_collection->getTracks()->count();
}

QHash<int, QByteArray>  AbstractPlaylist::roleNames() const
{
    return m_roles;
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

void AbstractPlaylist::setSignals()
{
    connect(m_collection, &Collection::tracksUpdated,
            this, &AbstractPlaylist::countChanged);
}

QString AbstractPlaylist::name() const
{
    return m_name;
}

void AbstractPlaylist::selectTrack(int index)
{
    Logger::log(m_collection->getTracks()->at(index)->title() + " selected");
    emit select(index);
}

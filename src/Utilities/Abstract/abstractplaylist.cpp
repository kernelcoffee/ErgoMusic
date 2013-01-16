#include "abstractplaylist.h"

AbstractPlaylist::AbstractPlaylist(QObject *parent) :
    QObject(parent)
{
}

//AbstractPlaylist::AbstractPlaylist(QObject *parent) :
//    QMediaPlaylist(parent)
//{
//}

//AbstractPlaylist::AbstractPlaylist()
//{}

AbstractPlaylist::~AbstractPlaylist()
{}

AbstractPlaylist::Type    AbstractPlaylist::getType(void) const
{
    return m_type;
}

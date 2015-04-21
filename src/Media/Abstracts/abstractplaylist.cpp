#include "abstractplaylist.h"
#include <QDebug>

AbstractPlaylist::AbstractPlaylist(QObject *parent) :
    QObject(parent)
  , m_id(-1)
  , m_name("")
{

}

AbstractPlaylist::~AbstractPlaylist()
{

}

int AbstractPlaylist::id() const
{
    return m_id;
}

QString AbstractPlaylist::name() const
{
    return m_name;
}

QList<Track*> AbstractPlaylist::tracks() const
{
    return m_tracks;
}

void AbstractPlaylist::addTrack(Track *track)
{
    m_tracks.append(track);
    emit updated();
}

void AbstractPlaylist::clear()
{
    m_tracks.clear();
}

#include "playlist.h"

Playlist::Playlist(QObject* parent)
{
}

Playlist::Playlist(QString name, QObject* parent)
{
    m_name = name;
}

Playlist::~Playlist()
{

}

void    Playlist::addTrack(Track* track)
{
    //m_list->append(track);
}

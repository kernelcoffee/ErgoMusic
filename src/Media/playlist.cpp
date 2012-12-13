#include "playlist.h"

Playlist::Playlist()
{
}

Playlist::Playlist(QString name)
{
    m_name = name;
}

Playlist::~Playlist()
{

}

void    Playlist::addTrack(Track* track)
{
    m_list->append(track);
}

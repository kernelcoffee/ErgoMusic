#include "playlist.h"

Playlist::Playlist()
{
}

Playlist::~Playlist()
{

}

void    Playlist::addTrack(Track* track)
{
    m_list->append(track);
}

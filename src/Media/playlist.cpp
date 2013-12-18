#include "playlist.h"
#include "coremanager.h"

Playlist::Playlist(QObject *parent) :
    AbstractPlaylist(parent)
{
    m_type = PLAYLIST;
    m_name = QString(tr(":unamed_playlist"));
    m_collection = CoreManager::instance()->media()->collection();
}

Playlist::~Playlist()
{

}


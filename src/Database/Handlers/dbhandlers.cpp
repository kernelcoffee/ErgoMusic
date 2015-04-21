#include "dbhandlers.h"

DbHandlers::DbHandlers(QObject *parent) :
    QObject(parent)
  , m_watchPlaylist(new WatchPlaylistDBHandler)
{

}

DbHandlers::~DbHandlers()
{

}

WatchPlaylistDBHandler* DbHandlers::WatchPlaylist()
{
    return m_watchPlaylist;
}

void DbHandlers::delayedInit()
{
    m_watchPlaylist->loadAll();
}

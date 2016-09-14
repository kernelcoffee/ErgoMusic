#include "mediacore.h"
#include "coremanager.h"

#include <QDebug>

MediaCore::MediaCore(CoreManager *parent) :
    AbstractCore(parent)
  , m_cores(parent)
  , m_library(new Collection)
  , m_watchPlaylists(new WatchPlaylists)
{
    qDebug() << "MediaCore";
}

MediaCore::~MediaCore()
{

}

void MediaCore::init()
{

}

void MediaCore::initSettings()
{

}

Collection* MediaCore::library() const
{
    return  m_library;
}

WatchPlaylists* MediaCore::watchPlaylists() const
{
    return m_watchPlaylists;
}

void MediaCore::delayedInit()
{
    DatabaseCore *db = m_cores->database();

    connect(m_watchPlaylists, &WatchPlaylists::watchPlaylistAdded,
            [=] (int index) { db->handlers()->WatchPlaylist()->save(m_watchPlaylists->at(index)); });
    connect(m_watchPlaylists, &WatchPlaylists::watchPlaylistUpdated,
            [=] (int index) { db->handlers()->WatchPlaylist()->update(m_watchPlaylists->at(index)); });
    connect(m_watchPlaylists, &WatchPlaylists::watchPlaylistRemoved,
            [=] (int index) { db->handlers()->WatchPlaylist()->remove(m_watchPlaylists->at(index)); });
}

void MediaCore::onAboutToQuit()
{

}


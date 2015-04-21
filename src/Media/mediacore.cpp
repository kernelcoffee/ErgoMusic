#include "mediacore.h"
#include "coremanager.h"

#include <QDebug>

MediaCore::MediaCore(QObject *parent) :
    AbstractCore(parent)
  , m_library(new Collection)
  , m_watchPlaylists(new WatchPlaylists)
  , m_metaData(new MetaDataHandler)
{

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

void MediaCore::initArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

void MediaCore::processArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

Collection* MediaCore::library() const
{
    return  m_library;
}

WatchPlaylists* MediaCore::watchPlaylists() const
{
    return m_watchPlaylists;
}

MetaDataHandler *MediaCore::metaDataHandler() const
{
    return m_metaData;
}

void MediaCore::delayedInit()
{
    DatabaseCore*   db = CoreManager::instance()->database();

    connect(m_watchPlaylists, &WatchPlaylists::watchPlaylistAdded,
            [=] (int index) { db->handlers()->WatchPlaylist()->save(m_watchPlaylists->at(index)); });
    connect(m_watchPlaylists, &WatchPlaylists::watchPlaylistUpdated,
            [=] (int index) { db->handlers()->WatchPlaylist()->update(m_watchPlaylists->at(index)); });
    connect(m_watchPlaylists, &WatchPlaylists::watchPlaylistRemoved,
            [=] (int index) { db->handlers()->WatchPlaylist()->remove(m_watchPlaylists->at(index)); });
}

void MediaCore::aboutToQuit()
{

}


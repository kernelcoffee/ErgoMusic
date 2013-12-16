#include "mediamanager.h"
#include "Utilities/logger.h"

MediaManager::MediaManager(QObject *parent) :
    QObject(parent)
{
    Logger::log("MediaManager - Initiatlization start", LOG_DEBUG);
    m_collection = new Collection;
    m_watchPlaylists = new WatchPlaylistsModel;
    m_library = new Library(m_collection);
}

MediaManager::~MediaManager()
{}

void    MediaManager::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
}

void MediaManager::initDummyData()
{
    m_watchPlaylists->addWatchPlaylist("test1", "/home/greys/Dropbox/Music/watchFolder");
}

QAbstractListModel *MediaManager::getCurrentModel() const
{

}

Library *MediaManager::library() const
{
    return m_library;
}

Collection *MediaManager::getCollection() const
{
    return  m_collection;
}

WatchPlaylistsModel *MediaManager::getWatchPlaylists() const
{
    return m_watchPlaylists;
}

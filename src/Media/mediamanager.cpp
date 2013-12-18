#include "mediamanager.h"
#include "Utilities/logger.h"

MediaManager::MediaManager(QObject *parent) :
    QObject(parent)
{
    Logger::log("MediaManager - Initiatlization start", LOG_DEBUG);
    m_collection = new Collection;
    m_watchPlaylists = new WatchPlaylistsModel;
    m_library = new Library(m_collection);
    m_currentModel = m_library;
}

MediaManager::~MediaManager()
{}

void    MediaManager::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
}

void MediaManager::initDummyData()
{
    m_watchPlaylists->addWatchPlaylist("/home/amoore/Dropbox/Music/watchFolder/");
}

void MediaManager::setCurrentModel(AbstractPlaylist * model)
{
    Logger::log("update set current model - " + model->name(), LOG_DEBUG);
    m_currentModel = model;
    Logger::log("currentModel -> " + model->name() + " " + QString::number(model->rowCount()), LOG_DEBUG);
    emit    currentModelUpdated();
}

AbstractPlaylist *MediaManager::currentModel() const
{
    return  m_currentModel;
}

Library *MediaManager::library() const
{
    return m_library;
}

Collection *MediaManager::collection() const
{
    return  m_collection;
}

WatchPlaylistsModel *MediaManager::watchPlaylists() const
{
    return m_watchPlaylists;
}

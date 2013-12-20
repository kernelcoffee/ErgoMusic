#include "coremanager.h"
#include "Utilities/logger.h"


CoreManager::CoreManager()
{
    Logger::log("CoreManager - contruction", LOG_DEBUG);
    m_databaseManager = new DatabaseManager();
    m_networkManager = new NetworkManager();
    m_audioManager = new AudioManager();
    m_mediaManager = new MediaManager();
}

CoreManager::~CoreManager()
{
}


void    CoreManager::aboutToQuit()
{
    Logger::log("About to quit");
}

void    CoreManager::initManagers(QStringList &arguments)
{
    Logger::log("CoreManager - initManagers", LOG_DEBUG);
    m_databaseManager->init(arguments);
    m_networkManager->init(arguments);
    m_audioManager->init(arguments);
    m_mediaManager->init(arguments);
    Logger::log("CoreManager - initManagers - End of managers initialization", LOG_DEBUG);
}

void    CoreManager::deleteManagers()
{}

DatabaseManager*    CoreManager::database() const
{
    return m_databaseManager;
}

NetworkManager*     CoreManager::network() const
{
    return m_networkManager;
}

AudioManager *CoreManager::audio() const
{
    return m_audioManager;
}

MediaManager *CoreManager::media() const
{
    return m_mediaManager;
}

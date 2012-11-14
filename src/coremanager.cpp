#include "coremanager.h"
#include "Utilities/logger.h"


CoreManager::CoreManager()
{
    Logger::log("CoreManager - contruction", LOG_DEBUG);
    m_databaseManager = new DatabaseManager();
    m_networkManager = new NetworkManager();
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
    Logger::log("CoreManager - initManager", LOG_DEBUG);
    m_databaseManager->init(arguments);
    m_networkManager->init(arguments);
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

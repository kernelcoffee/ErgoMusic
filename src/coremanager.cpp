#include "coremanager.hpp"

CoreManager::CoreManager()
{
    m_databaseManager = new DatabaseManager();
    m_networkManager = new NetworkManager();
}

CoreManager::~CoreManager()
{}


void    CoreManager::aboutToQuit()
{}

void    CoreManager::initManagers(QStringList &arguments)
{
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

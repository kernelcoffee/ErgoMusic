#include "collection.h"
#include "Utilities/logger.h"
#include "coremanager.h"

Collection::Collection()
{
    Logger::log("Create collection instance", LOG_DEBUG);
}


Collection::~Collection()
{}

void Collection::init(QStringList &arguments, QSplashScreen* splash)
{
    Logger::log("Collection - Initialization", LOG_DEBUG);

    m_watchPlaylist = new WatchPlaylist();
//    DatabaseManager* dbmanager = CoreManager::instance()->database();
}

WatchPlaylist*  Collection::getWatchPlaylist() const
{
    return m_watchPlaylist;
}

void Collection::createPlaylist(QString name)
{
}


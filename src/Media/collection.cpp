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
    DatabaseManager* dbmanager = CoreManager::instance()->database();

}


void Collection::createPlaylist(QString name)
{
}

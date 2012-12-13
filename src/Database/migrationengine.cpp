#include "migrationengine.h"
#include "../Utilities/logger.h"

MigrationEngine::MigrationEngine()
{
}

MigrationEngine::~MigrationEngine()
{}

void    MigrationEngine::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
}

void    MigrationEngine::setQuery(QSqlQuery* query)
{
    if (!query)
        Logger::log("MigrationEngine - setQuery Failed", LOG_CRIT);
    m_query = query;

}

void    MigrationEngine::migrate()
{
    Logger::log("MigrationEngine - Start migration", LOG_DEBUG);
}

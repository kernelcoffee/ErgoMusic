#include "migrationengine.hpp"
#include "../Utilities/logger.hpp"

MigrationEngine::MigrationEngine()
{
}

MigrationEngine::~MigrationEngine()
{}

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
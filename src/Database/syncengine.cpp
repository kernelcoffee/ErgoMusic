#include "syncengine.hpp"

SyncEngine::SyncEngine()
{
}

SyncEngine::~SyncEngine()
{}

void    SyncEngine::init(QStringList& argument)
{}

void    SyncEngine::setQuery(QSqlQuery *query)
{
    m_query = query;
}

#include "syncengine.h"

SyncEngine::SyncEngine()
{
}

SyncEngine::~SyncEngine()
{}

void    SyncEngine::init(QStringList& arguments)
{
    Q_UNUSED(arguments);
}

void    SyncEngine::setQuery(QSqlQuery *query)
{
    m_query = query;
}

#include "integrityengine.h"

IntegrityEngine::IntegrityEngine()
{
}

IntegrityEngine::~IntegrityEngine()
{}

void    IntegrityEngine::init(QStringList &arguments)
{
    Q_UNUSED(arguments);
}

void    IntegrityEngine::setQuery(QSqlQuery *query)
{
    m_query = query;
}

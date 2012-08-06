#include "integrityengine.hpp"

IntegrityEngine::IntegrityEngine()
{
}

IntegrityEngine::~IntegrityEngine()
{}

void    IntegrityEngine::init(QStringList &arguments)
{}

void    IntegrityEngine::setQuery(QSqlQuery *query)
{
    m_query = query;
}

#ifndef INTEGRITYENGINE_H
#define INTEGRITYENGINE_H

#include <QSqlQuery>

/*
 * This engine check and garanty the integrity of the data
 * between the database and the filesystem
 */

class IntegrityEngine
{
public:
    IntegrityEngine();
    ~IntegrityEngine();
    void    init(QStringList&);
    void    setQuery(QSqlQuery*);
private:
    QSqlQuery*  m_query;
};

#endif // INTEGRITYENGINE_H

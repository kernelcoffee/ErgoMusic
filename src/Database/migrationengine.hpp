#ifndef MIGRATIONENGINE_HPP
#define MIGRATIONENGINE_HPP

#include <QSqlQuery>

class MigrationEngine
{
public:
    MigrationEngine();
    ~MigrationEngine();
    void    setQuery(QSqlQuery*);
    void    migrate();
private:
    QSqlQuery*  m_query;
};

#endif // MIGRATIONENGINE_HPP

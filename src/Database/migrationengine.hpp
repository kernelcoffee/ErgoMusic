#ifndef MIGRATIONENGINE_HPP
#define MIGRATIONENGINE_HPP

#include <QSqlQuery>

/**
  * The migration engine create and upgrade the database
  * layout through the different versions.
  */


class MigrationEngine
{
public:
    MigrationEngine();
    ~MigrationEngine();
    void    init(QStringList&);
    void    setQuery(QSqlQuery*);
    void    migrate();
private:
    QSqlQuery*  m_query;
};

#endif // MIGRATIONENGINE_HPP

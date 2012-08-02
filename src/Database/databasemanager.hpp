#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include "importengine.hpp"
#include "integrityengine.hpp"
#include "migrationengine.hpp"
#include "syncengine.hpp"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QFile>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();
private:
    void                openDatabase();
    bool                connect();

    QSqlDatabase        m_db;
    QSqlQuery*          m_query;
    QFile*              m_dbFile;

    ImportEngine*       m_importEngine;
    IntegrityEngine*    m_integrityEngine;
    MigrationEngine*    m_migrationEngine;
    SyncEngine*         m_syncEngine;
};

#endif // DATABASEMANAGER_HPP

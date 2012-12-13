#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "importengine.h"
#include "integrityengine.h"
#include "migrationengine.h"
#include "syncengine.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QFile>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    void                init(QStringList&);
    ImportEngine*       importEngine() const;
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

#endif // DATABASEMANAGER_H

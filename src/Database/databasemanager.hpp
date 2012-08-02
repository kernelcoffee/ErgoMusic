#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include "importengine.hpp"
#include "integrityengine.hpp"
#include "migrationengine.hpp"
#include "syncengine.hpp"

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();
private:
    ImportEngine*       m_importEngine;
    IntegrityEngine*    m_integrityEngine;
    MigrationEngine*    m_migrationEngine;
    SyncEngine*         m_syncEngine;
};

#endif // DATABASEMANAGER_HPP

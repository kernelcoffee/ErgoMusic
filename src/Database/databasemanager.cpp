#include "databasemanager.hpp"

DatabaseManager::DatabaseManager()
{
    m_importEngine = new ImportEngine();
    m_integrityEngine = new IntegrityEngine();
    m_migrationEngine = new MigrationEngine();
    m_syncEngine = new SyncEngine();
}

DatabaseManager::~DatabaseManager()
{
    delete m_importEngine;
    delete m_integrityEngine;
    delete m_migrationEngine;
    delete m_syncEngine;
}

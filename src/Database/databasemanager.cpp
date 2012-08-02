#include "databasemanager.hpp"
#include "../Utilities/logger.hpp"

#include <QDir>
#include <QtSql/QSqlError>

DatabaseManager::DatabaseManager()
{
    Logger::log("DatabaseManager - Initiatlization start", LOG_DEBUG);

    QSettings   settings;

    m_importEngine = new ImportEngine();
    m_integrityEngine = new IntegrityEngine();
    m_migrationEngine = new MigrationEngine();
    m_syncEngine = new SyncEngine();


    if (settings.value("dbType").toString() == "SQLITE")
        m_db = QSqlDatabase::addDatabase("QSQLITE");
    else
        Logger::log("Database type not valid.", LOG_CRIT);

    openDatabase();
    Logger::log("DatabaseManager - Initiatlization end", LOG_DEBUG);
}

DatabaseManager::~DatabaseManager()
{
    delete m_importEngine;
    delete m_integrityEngine;
    delete m_migrationEngine;
    delete m_syncEngine;
}

void    DatabaseManager::openDatabase()
{
    QDir    dir;
    QSettings   settings;

    m_dbFile = new QFile(settings.value("dbPath").toString() + "ergoMusicDB.sqlite");
    dir.mkpath(settings.value("dbPath").toString());
    Logger::log("DataManager - m_dbFile init OK " + settings.value("dbPath").toString() + "database.sqlite", LOG_DEBUG);

    if (connect() ==  false)
        Logger::log("DatabaseManager - Connect Failed", LOG_CRIT);

    m_query = new QSqlQuery(m_db);
    m_migrationEngine->setQuery(m_query);
    m_migrationEngine->migrate();
}

bool    DatabaseManager::connect()
{
    QSettings settings;

    if (m_dbFile->exists() == false)
    {
        Logger::log("DatabaseManager - Database file doesn't exist", LOG_DEBUG);
        if (m_dbFile->open(QFile::ReadWrite))
            Logger::log("DatabaseManager - Opening Database file OK", LOG_DEBUG);
        else
            return false;
    }
    m_db.setDatabaseName(settings.value("dbName").toString());
    return m_db.open();
}

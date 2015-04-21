#include "databasecore.h"
#include "Migration/migrationengine.h"

#include <QSettings>
#include <QDir>
#include <QStandardPaths>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

DatabaseCore::DatabaseCore(QObject *parent) :
    AbstractCore(parent)
  , m_handlers(new DbHandlers)
{
}

DatabaseCore::~DatabaseCore()
{

}

void DatabaseCore::init()
{
    QSettings settings;

    if(!(settings.value("database/type", "QSQLITE").toString() == "QSQLITE"))
        qCritical() << "Database type proper value " << settings.value("database/type").toString();

    _openDatabase();

    qDebug() << "pre migration DB tables : ";
    for (auto table : m_db.tables())
        qDebug() << table;

    MigrationEngine mEngine(this);
    mEngine.migrate();


    // set reset database
//    if (getParameter("reset", false) == true)
//    {
        // qDebug() << "DB reset requested";
        // Undo all migrations
//       mEngine.undo();
        // Migrate database to new schema
//        mEngine.migrate();
//    }
}

void DatabaseCore::initSettings()
{
    QSettings settings;

    settings.setValue("database/type", "QSQLITE");
    settings.setValue("database/path", QStandardPaths::writableLocation(QStandardPaths::DataLocation) + QDir::separator());
    settings.setValue("database/name", qAppName() + ".sqlite");
}

void DatabaseCore::initArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

void DatabaseCore::processArguments(QCommandLineParser &cmd)
{
    Q_UNUSED(cmd)
}

int DatabaseCore::currentMigration() const
{
    QSettings   settings;

    QVariant	value = settings.value("database/migration");
    if (value.isNull())
        return 0;
    else
        return value.toInt();
}

DbHandlers *DatabaseCore::handlers() const
{
    return m_handlers;
}

void DatabaseCore::delayedInit()
{
    m_handlers->delayedInit();
}

void DatabaseCore::aboutToQuit()
{
    m_db.close();
}

void DatabaseCore::_openDatabase()
{
    QSettings   settings;

    QDir        dir(settings.value("database/path").toString());
    dir.mkpath(dir.absolutePath());

    m_db = QSqlDatabase::addDatabase(settings.value("database/type").toString());
    m_db.setDatabaseName(settings.value("database/path").toString() + settings.value("database/name").toString());
    m_db.setUserName("ErgoMusic");

    if (!m_db.open())
        qCritical() << "Open DB failed : " << m_db.lastError();

}

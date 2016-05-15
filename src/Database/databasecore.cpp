#include "databasecore.h"
#include "Migration/migrationengine.h"
#include "coremanager.h"

#include <QSettings>
#include <QDir>
#include <QStandardPaths>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

DatabaseCore::DatabaseCore(CoreManager *cores) :
    AbstractCore(cores)
  , m_cores(cores)
  , m_handlers(new DbHandlers)
{
}

DatabaseCore::~DatabaseCore()
{

}

void DatabaseCore::init()
{
    _openDatabase();

    qDebug() << "pre migration DB tables : ";
    for (auto table : m_db.tables())
        qDebug() << table;

    MigrationEngine mEngine(this);
    mEngine.migrate();
}

void DatabaseCore::initSettings()
{
    QSettings settings;

    settings.beginGroup("database");
    settings.setValue("type", "QSQLITE");
    settings.setValue("path", QStandardPaths::writableLocation(QStandardPaths::DataLocation) + QDir::separator());
    settings.setValue("name", qAppName() + ".sqlite");
    settings.endGroup();
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
    QSettings settings;

    QVariant value = settings.value("database/migration");
    if (value.isNull())
        return 0;
    else
        return value.toInt();

    int schema_version = 0;

    QSqlQuery query("SELECT version FROM schema_version");
    if (query.next()) {
        schema_version = query.value(0).toInt();'
    }
}

DbHandlers *DatabaseCore::handlers() const
{
    return m_handlers;
}

void DatabaseCore::delayedInit()
{
    m_handlers->delayedInit();
}

void DatabaseCore::onAboutToQuit()
{
    m_db.close();
}

void DatabaseCore::_openDatabase()
{
    QSettings settings;
    QDir dir(settings.value("database/path").toString());

    dir.mkpath(dir.absolutePath());

    m_db = QSqlDatabase::addDatabase(settings.value("database/type").toString());
    m_db.setDatabaseName(settings.value("database/path").toString() + settings.value("database/name").toString());
    m_db.setUserName("ErgoMusic");

    if (!m_db.open())
        qCritical() << "Open DB failed : " << m_db.lastError();

}

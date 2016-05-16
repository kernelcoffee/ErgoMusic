#include "../migration_list.h"
#include <QDebug>

static const QString schemaTable = "schema_version";

void InitialMigration::up()
{
    createTable(schemaTable, "'id' INTEGER PRIMARY KEY NOT NULL UNIQUE, 'version' INTEGER");
    exec("INSERT INTO `schema_version`(`id`,`version`) VALUES (1,0)");
}

void InitialMigration::down()
{
    dropTable("schema_verison");
}

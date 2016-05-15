#include "../migration_list.h"
#include <QDebug>

void	WatchPlaylistMigration::up()
{
    qDebug() << "WatchPlaylist up";
    createTable("watchplaylists", "'id' INTEGER PRIMARY KEY  NOT NULL  UNIQUE , 'name' VARCHAR, 'path' VARCHAR");
    exec("CREATE UNIQUE INDEX watchplaylist_id ON watchplaylists(id)");
}

void	WatchPlaylistMigration::down()
{
    dropTable("watchplaylists");
}

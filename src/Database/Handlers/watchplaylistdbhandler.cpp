#include "watchplaylistdbhandler.h"
#include "Media/Playlists/watchplaylist.h"
#include "coremanager.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QDebug>

const QString dbName = "watchplaylists";

WatchPlaylistDBHandler::WatchPlaylistDBHandler(QObject *parent) :
    QObject(parent)
{

}

WatchPlaylistDBHandler::~WatchPlaylistDBHandler()
{

}

void WatchPlaylistDBHandler::loadAll()
{
    WatchPlaylists* playlists = CoreManager::instance()->media()->watchPlaylists();
    QSqlQuery query("SELECT * FROM watchplaylists");
    query.exec();

    while(query.next())
    {
        int		id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString	path = query.value(2).toString();

        qDebug() << id << name << path;
        WatchPlaylist* playlist = new WatchPlaylist(id, name, path);
        if (playlists->checkExistingPath(playlist->path())) {
            remove(playlist);
            delete playlist;
        } else {
            playlists->addWatchPlaylist(playlist);
        }
    }
}

void WatchPlaylistDBHandler::save(WatchPlaylist *playlist)
{
    qDebug() << "Saving watchplaylist " << playlist->name();

    QSqlQuery query;
    query.prepare("INSERT INTO " + dbName + "(name, path) VALUES (:name, :path)");
    query.bindValue(":name", playlist->name());
    query.bindValue(":path", playlist->path());

    if (!query.exec())
        qDebug() << "Can't save watchplaylist path : " << query.lastError();
    else
        qDebug() << "new path saved" << query.lastError();;

}

void WatchPlaylistDBHandler::update(WatchPlaylist *playlist)
{
    qDebug() << "Updating watchplaylist " << playlist->name();

    QSqlQuery query;
    query.prepare("UPDATE " + dbName + " SET 'name' = :name, 'path' = :path WHERE  'id' = :id");
    query.bindValue(":id", playlist->id());
    query.bindValue(":name", playlist->name());
    query.bindValue(":path", playlist->path());

    if (!query.exec())
        qDebug() << "Can't update watchplaylist : " << query.lastError();
}

void WatchPlaylistDBHandler::remove(WatchPlaylist *playlist)
{
    qDebug() << "Removing watchplaylist " << playlist->name();

    QSqlQuery query;
    query.prepare("DELETE FROM watchplaylists WHERE id = :id");
    query.bindValue(":id", playlist->id());

    if (!query.exec())
        qDebug() << "Can't remove watchplaylist" << playlist->id() << query.lastError().text();
}

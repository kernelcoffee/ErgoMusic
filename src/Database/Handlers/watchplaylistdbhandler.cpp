#include "watchplaylistdbhandler.h"
#include "Media/Playlists/watchplaylist.h"
#include "coremanager.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QDebug>

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

        playlists->addWatchPlaylist(new WatchPlaylist(id, name, path));
        qDebug() << id << name << path;
    }
}

void WatchPlaylistDBHandler::save(WatchPlaylist *playlist)
{
    QSqlQuery query;
    query.prepare("INSERT INTO watchplaylists(name, path) VALUES (:name, :path)");
    query.bindValue(":name", playlist->name());
    query.bindValue(":path", playlist->path());

    if (!query.exec())
        qDebug() << "Can't save watchplaylist path : " << query.lastError();
    else
        qDebug() << "new path saved" << query.lastError();;

}

void WatchPlaylistDBHandler::update(WatchPlaylist *playlist)
{
    QSqlQuery query;

    query.prepare("UPDATE watchplaylists SET 'name' = :name, 'path' = :path WHERE  'id' = :id");
    query.bindValue(":id", playlist->id());
    query.bindValue(":name", playlist->name());
    query.bindValue(":path", playlist->path());

    if (!query.exec())
        qDebug() << "Can't update watchplaylist : " << query.lastError();
}

void WatchPlaylistDBHandler::remove(WatchPlaylist *playlist)
{
    QSqlQuery query;

    query.prepare("DELETE FROM watchplaylists WHERE id = :id");
    query.bindValue(":id", playlist->id());

    if (!query.exec())
        qDebug() << "Can't remove watchplaylist" << playlist->id() << query.lastError().text();
}

#include "watchplaylist.h"
#include "Utilities/logger.h"

#include <QSettings>
#include <QDir>

WatchPlaylist::WatchPlaylist(QObject *parent) :
    QFileSystemWatcher(parent)
{
    QSettings   settings;

    if (settings.value("watchFolderEnable").toBool() == true)
        update();
}

WatchPlaylist::~WatchPlaylist()
{}

void    WatchPlaylist::updateWatchFolder()
{
    QSettings settings;

    if (settings.value("watchFolderEnable").toBool() == true)
        update();
}

void    WatchPlaylist::update()
{
    QSettings   settings;
    QDir        watchFolder(settings.value("watchFolder").toString());

    if (watchFolder.exists())
    {

        Logger::log("WatchPlaylist - Path correct : " + watchFolder.absolutePath());
    }
    else
    {
        Logger::log("WatchPlaylist - Path incorrect : " + watchFolder.absolutePath(), LOG_WARNING);
    }

}

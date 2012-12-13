#include "watchplaylist.h"
#include "Utilities/logger.h"
#include "coremanager.h"

#include <QSettings>
#include <QDir>

WatchPlaylist::WatchPlaylist(QObject *parent) :
    QFileSystemWatcher(parent)
{
    QSettings   settings;

    Logger::log("WatchPlaylist - Constructor", LOG_DEBUG);
    if (settings.value("watchFolderActivated").toBool() == true) {
        _update();
        directoryChanged(settings.value("watchFolder").toString());
    }
}

WatchPlaylist::~WatchPlaylist()
{}

void    WatchPlaylist::update()
{
    QSettings settings;

    Logger::log("WatchPlaylist - update", LOG_DEBUG);

    if (settings.value("watchFolderActivated").toBool() == true)
    {
        _update();
    }
    else
        _disable();
}

void    WatchPlaylist::_refresh(QString path)
{
    Logger::log("WatchPlaylist - _refresh - watchFolder modified at path " + path, LOG_DEBUG);
    m_list = CoreManager::instance()->database()->importEngine()->importPath(path);
    refreshed();
}

void    WatchPlaylist::_update()
{
    QSettings   settings;
    QDir        watchFolder(settings.value("watchFolder").toString());

    if (watchFolder.exists())
    {
        Logger::log("WatchPlaylist - Path correct : " + watchFolder.absolutePath(), LOG_DEBUG);
        removePaths(directories());
        addPath(watchFolder.absolutePath());
        if (receivers(SIGNAL(directoryChanged(QString))) == 0) {
            Logger::log("WatchPlaylist - _update - signal not set -> connecting", LOG_DEBUG);
            connect(this, SIGNAL(directoryChanged(QString)), this, SLOT(_refresh(QString)));
        }
    }
    else
    {
        Logger::log("WatchPlaylist - Path incorrect : " + watchFolder.absolutePath(), LOG_WARNING);
    }
}

void    WatchPlaylist::_disable()
{
    Logger::log("WatchPlaylist - _disable", LOG_DEBUG);
    if (receivers(SIGNAL(directoryChanged(QString))) > 0)
        disconnect(this, SIGNAL(directoryChanged(QString)), this, SLOT(_refresh(QString)));
    removePaths(directories());

}

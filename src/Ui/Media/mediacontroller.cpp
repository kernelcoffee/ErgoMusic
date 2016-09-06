#include "mediacontroller.h"
#include "coremanager.h"

#include "Media/Commands/addwatchplaylistcommand.h"
#include "Media/Commands/removewatchplaylistcommand.h"

#include <QDebug>

MediaController::MediaController(QObject *parent) :
    QObject(parent)
  , m_media(CoreManager::instance()->media())
  , m_watchPlaytlistsModel(new WatchPlaylistsModel(m_media->watchPlaylists()))
{
}

MediaController::~MediaController()
{

}

void MediaController::addWatchPlaylist(QString path)
{
    CoreManager::instance()->addCommand(new AddWatchPlaylistCommand(m_media->watchPlaylists(), path));
}

void MediaController::refreshWatchPlaylist(int index)
{
    m_media->watchPlaylists()->refreshWatchPlaylist(index);
}

void MediaController::removeWathPlaylist(int index)
{
    CoreManager::instance()->addCommand(new RemoveWatchPlaylistCommand(m_media->watchPlaylists(), m_media->watchPlaylists()->at(index)));
}

WatchPlaylistsModel* MediaController::watchPlaylistsModel() const
{
    return m_watchPlaytlistsModel;
}

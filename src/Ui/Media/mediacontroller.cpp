#include "mediacontroller.h"
#include "coremanager.h"

#include <QDebug>
#include "Media/Commands/addwatchplaylistcommand.h"
#include "Media/Commands/removewatchplaylistcommand.h"

MediaController::MediaController(QObject *parent) :
    QObject(parent)
  , m_media(CoreManager::instance()->media())
  , m_watchPlaytlistsModel(m_media->watchPlaylists())
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

WatchPlaylistsMenuModel& MediaController::watchPlaylistsModel()
{
    return m_watchPlaytlistsModel;
}

int MediaController::contextIndex() const
{
    return m_contextIndex;
}

void MediaController::setContextIndex(int arg)
{
    if (m_contextIndex == arg)
        return;

    m_contextIndex = arg;
    emit contextIndexChanged(arg);
}

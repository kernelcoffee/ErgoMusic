#include "mediacontroller.h"
#include "coremanager.h"

#include <QDebug>

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
    m_media->watchPlaylists()->addWatchPlaylist(path);
}

void MediaController::refreshWatchPlaylist(int index)
{
    m_media->watchPlaylists()->refreshWatchPlaylist(index);
}

void MediaController::removeWathPlaylist(int index)
{
    m_media->watchPlaylists()->removeWatchPlaylist(index);
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

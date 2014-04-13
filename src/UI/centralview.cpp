#include "centralview.h"
#include "common.h"
#include "Utilities/logger.h"

CentralView::CentralView(QQuickItem *parent) :
    QQuickItem(parent)
{
    m_media = CoreManager::instance()->media();
}

void CentralView::setModel(int type, int index)
{
//    switch (type) {
//    case LIBRARY:
//        Logger::log("CentralView - Select Library", LOG_DEBUG);
//        m_media->setCurrentModel(m_media->library());
//        m_state = "songList";
//        break;
//    case WATCHPLAYLIST:
//        Logger::log("CentralView - Select WatchPlaylist", LOG_DEBUG);
//        m_media->setCurrentModel(m_media->watchPlaylists()->getWatchPlaylist(index));
//        m_state = "songList";
//        break;
//    }
//    emit modelChanged();
//    emit stateChanged();
}

PlaylistModel *CentralView::model() const
{
//    if (CoreManager::instance()->media()->currentModel()) {
////        Logger::log("CentralView - get Model -> " + CoreManager::instance()->media()->currentModel()->name(), LOG_DEBUG);
//        return CoreManager::instance()->media()->currentModel();
//    }
//    CoreManager::instance()->media()->setCurrentModel(CoreManager::instance()->media()->library());
    return CoreManager::instance()->media()->currentModel();
}

QString CentralView::state() const
{
    return m_state;
}

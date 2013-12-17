#include "centralview.h"
#include "common.h"
#include "Utilities/logger.h"

CentralView::CentralView(QQuickItem *parent) :
    QQuickItem(parent)
{

}

void CentralView::setModel(int type, int index)
{
    switch (type) {
    case LIBRARY:
        Logger::log("CentralView - Select Library", LOG_DEBUG);
        break;
    case WATCHPLAYLIST:
        WatchPlaylist* wpl = dynamic_cast<WatchPlaylist*>(CoreManager::instance()->media()->watchPlaylists()->get(index));
        CoreManager::instance()->media()->setCurrentModel(wpl);
        Logger::log("CentralView - Select WatchPlaylist " + wpl->name(), LOG_DEBUG);
        break;
//    default:
//        Logger::log("CentralView -  Default");
//        break;
    }
    emit modelChanged();
}

AbstractPlaylist *CentralView::model() const
{
    if (CoreManager::instance()->media()->currentModel()) {
        qDebug() << "Debug centralWidget -> currentModel " << CoreManager::instance()->media()->currentModel();
        Logger::log("CentralView - get Model -> " + CoreManager::instance()->media()->currentModel()->name(), LOG_DEBUG);
        return CoreManager::instance()->media()->currentModel();
    }
}

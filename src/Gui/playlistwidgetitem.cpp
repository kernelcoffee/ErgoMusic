#include "playlistwidgetitem.h"
#include "Utilities/logger.h"

PlaylistWidgetItem::PlaylistWidgetItem(const QString title, TreeItem* parent) :
    TreeItem(title, parent)
{
    Logger::log("PlaylistWidgetItem - Create instance", LOG_DEBUG);
}

#include "playlistwidgetitem.h"
#include "Utilities/logger.h"

PlaylistWidgetItem::PlaylistWidgetItem(const QString title, TreeItem* parent) :
    TreeItem(title, parent), m_type(INVALID), m_index(0)
{
    Logger::log("PlaylistWidgetItem - Create instance", LOG_DEBUG);
}

PlaylistWidgetItem::PlaylistWidgetItem(const QString title, Type type, TreeItem* parent) :
    TreeItem(title, parent), m_type(type), m_index(0)
{
    Logger::log("PlaylistWidgetItem - Create instance", LOG_DEBUG);
}

PlaylistWidgetItem::PlaylistWidgetItem(const QString title, Type type, int index, TreeItem* parent) :
    TreeItem(title, parent), m_type(type), m_index(index)
{
    Logger::log("PlaylistWidgetItem - Create instance", LOG_DEBUG);
}

PlaylistWidgetItem::Type    PlaylistWidgetItem::getType(void) const
{
    return m_type;
}

int PlaylistWidgetItem::getIndex() const
{
    return m_index;
}

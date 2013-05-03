#include "sidebarwidgetitem.h"
#include "Utilities/logger.h"

SidebarWidgetItem::SidebarWidgetItem(const QString title, TreeItem* parent) :
    TreeItem(title, parent), m_type(INVALID), m_index(0)
{
    Logger::log("SidebarWidgetItem - Create instance", LOG_DEBUG);
}

SidebarWidgetItem::SidebarWidgetItem(const QString title, Type type, TreeItem* parent) :
    TreeItem(title, parent), m_type(type), m_index(0)
{
    Logger::log("SidebarWidgetItem - Create instance", LOG_DEBUG);
}

SidebarWidgetItem::SidebarWidgetItem(const QString title, Type type, int index, TreeItem* parent) :
    TreeItem(title, parent), m_type(type), m_index(index)
{
    Logger::log("SidebarWidgetItem - Create instance", LOG_DEBUG);
}

SidebarWidgetItem::Type    SidebarWidgetItem::getType(void) const
{
    return m_type;
}

int SidebarWidgetItem::getIndex() const
{
    return m_index;
}

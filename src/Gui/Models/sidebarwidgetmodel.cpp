#include "sidebarwidgetmodel.h"

#include "Utilities/logger.h"

// Library
// - Music
// - Podcast
//
// Store
//
// Devices
//
// Genius
//
// Playlist
// - watchlist
// - dynamic playlist
// - static playlist


SidebarWidgetModel::SidebarWidgetModel() : TreeModel()
{
    Logger::log("SidebarWidgetModel - init instance", LOG_DEBUG);

    setupModelData();
}

void    SidebarWidgetModel::setupModelData()
{
    Logger::log("SidebarWidgetModel - setupModelData", LOG_DEBUG);

    // Default menus
    SidebarWidgetItem* librarySection = new SidebarWidgetItem(QString("Library"), rootItem);
    librarySection->setFlags(Qt::NoItemFlags);
    rootItem->appendChild(librarySection);

    SidebarWidgetItem* music = new SidebarWidgetItem("music", SidebarWidgetItem::LIBRARY, librarySection);
    librarySection->appendChild(music);

    // Playlist
    SidebarWidgetItem* SidebarSection = new SidebarWidgetItem("Playlist", rootItem);
    SidebarSection->setDisabled(true);
    rootItem->appendChild(SidebarSection);
    // Watchlist
    SidebarWidgetItem* watchlist = new SidebarWidgetItem("watchplaylist", SidebarWidgetItem::WATCHPLAYLIST, SidebarSection);
    SidebarSection->appendChild(watchlist);
    // DynamicPlaylist
    // StaticPlaylist

    Logger::log("SidebarWidgetModel - setupModelData - END", LOG_DEBUG);
}


#include "playlistwidgetmodel.h"

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


PlaylistWidgetModel::PlaylistWidgetModel() : TreeModel()
{
    Logger::log("PlaylistWidgetModel - init instance", LOG_DEBUG);

    setupModelData();
}

void    PlaylistWidgetModel::setupModelData()
{
    Logger::log("PlaylistWidgetModel - setupModelData", LOG_DEBUG);

    // Default menus
    PlaylistWidgetItem* librarySection = new PlaylistWidgetItem(QString("Library"), rootItem);
    librarySection->setFlags(Qt::NoItemFlags);
    rootItem->appendChild(librarySection);

    PlaylistWidgetItem* music = new PlaylistWidgetItem("music", PlaylistWidgetItem::LIBRARY, librarySection);
    librarySection->appendChild(music);

    // Playlist
    PlaylistWidgetItem* playlistSection = new PlaylistWidgetItem("Playlist", rootItem);
    playlistSection->setDisabled(true);
    rootItem->appendChild(playlistSection);
    // Watchlist
    PlaylistWidgetItem* watchlist = new PlaylistWidgetItem("watchplaylist", PlaylistWidgetItem::WATCHPLAYLIST, playlistSection);
    playlistSection->appendChild(watchlist);
    // DynamicPlaylist
    // StaticPlaylist

    Logger::log("PlaylistWidgetModel - setupModelData - END", LOG_DEBUG);
}


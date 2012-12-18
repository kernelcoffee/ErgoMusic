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

QVariant    PlaylistWidgetModel::data(const QModelIndex &index, int role) const
{
    Logger::log("PlaylistWidgetModel - data");
    if (!index.isValid())
        return QVariant();
    if (role != Qt::DisplayRole)
        return QVariant();

    PlaylistWidgetItem* item = static_cast<PlaylistWidgetItem*>(index.internalPointer());

    if (role == Qt::ToolTipRole)
        return item->data(index.column());

    return qVariantFromValue((void*)item);
}

void    PlaylistWidgetModel::setupModelData()
{
    Logger::log("PlaylistWidgetModel - setupModelData", LOG_DEBUG);

    PlaylistWidgetItem* librarySection = new PlaylistWidgetItem(QString("Library"), rootItem);
    rootItem->appendChild(librarySection);

    PlaylistWidgetItem* music = new PlaylistWidgetItem("music", librarySection);
    librarySection->appendChild(music);

    PlaylistWidgetItem* playlistSection = new PlaylistWidgetItem("Playlist", rootItem);
    rootItem->appendChild(playlistSection);

    PlaylistWidgetItem* watchlist = new PlaylistWidgetItem("watchplaylist", playlistSection);
    playlistSection->appendChild(watchlist);

    Logger::log("PlaylistWidgetModel - setupModelData - END", LOG_DEBUG);
}


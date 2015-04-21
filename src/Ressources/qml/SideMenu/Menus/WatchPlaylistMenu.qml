import QtQuick 2.0
import QtQuick.Controls 1.2

Menu {
    id: watchPlaylistsMenu

    MenuItem {
        text: qsTr("&Edit")
        onTriggered: console.log("edit watch playlist " + mediaController.contextIndex)
    }

    MenuItem {
        text: qsTr("&Refresh")
        onTriggered: mediaController.refreshWatchPlaylist(mediaController.contextIndex);
    }

    MenuItem {
        text: qsTr("&Remove")
        onTriggered: mediaController.removeWathPlaylist(mediaController.contextIndex)
    }
}

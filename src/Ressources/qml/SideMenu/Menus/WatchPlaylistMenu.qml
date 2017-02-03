import QtQuick 2.8
import QtQuick.Controls 1.4
import ErgoMusic 1.0

Menu {
    id: watchPlaylistsMenu

    property int index

    MenuItem {
        text: qsTr("&Edit")
        onTriggered: console.warn("edit watch playlist " + index)
    }

    MenuItem {
        text: qsTr("&Refresh")
        onTriggered: uiCore.mediaController.refreshWatchPlaylist(index);
    }

    MenuItem {
        text: qsTr("&Remove")
        onTriggered: uiCore.mediaController.removeWathPlaylist(index)
    }
}

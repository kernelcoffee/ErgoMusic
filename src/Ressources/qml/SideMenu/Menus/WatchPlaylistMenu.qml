import QtQuick 2.0
import QtQuick.Controls 1.2

Menu {
    id: watchPlaylistsMenu

    property int index

    MenuItem {
        text: qsTr("&Edit")
        onTriggered: console.warn("edit watch playlist " + index)
    }

    MenuItem {
        text: qsTr("&Refresh")
        onTriggered: mediaController.refreshWatchPlaylist(index);
    }

    MenuItem {
        text: qsTr("&Remove")
        onTriggered: mediaController.removeWathPlaylist(index)
    }
}

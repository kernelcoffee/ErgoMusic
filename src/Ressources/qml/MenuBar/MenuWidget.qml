import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

MenuBar {
    Menu {
        title: qsTr("&File")
        MenuItem {
            id: addWatchPlaylistMenuItem
            text: qsTr("&New WatchPlaylist")
            onTriggered: dialogLoader.open("qrc:/qml/Dialogs/AddWatchPlaylistDialog.qml")
        }
        MenuItem {
            text: qsTr("&Open")
            onTriggered: messageDialog.show(qsTr("Open action triggered"))
        }
        MenuItem {
            text: qsTr("&Exit")
            shortcut: "alt + F4"
            onTriggered: Qt.quit()
        }
    }
    Menu {
        title: qsTr("&Edit")
        MenuItem {
            id: undo
            text: qsTr("&undo");
            onTriggered: viewController.undo()
        }
        MenuItem {
            id: redo
            text: qsTr("&redo");
            onTriggered: viewController.redo()
        }
        MenuItem {
            id: options
            text: qsTr("&options");
        }
    }
    Menu {
        title: qsTr("&Help")
        MenuItem {
            text: qsTr("&About %1").arg(Qt.application.name)
            onTriggered: ;
        }
        MenuItem {
            text: qsTr("&About Qt")
            onTriggered: ;
        }
    }
}

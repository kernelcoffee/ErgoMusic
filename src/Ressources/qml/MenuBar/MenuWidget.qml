import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

import ErgoMusic 1.0

MenuBar {
    id: menubar
    property MediaController mediaController

    Menu {
        title: qsTr("&File")
        MenuItem {
            id: addWatchPlaylistMenuItem
            text: qsTr("New &WatchPlaylist")
            shortcut: "Ctrl+Shift+N"
            onTriggered: dialogLoader.open("qrc:/qml/Dialogs/AddWatchPlaylistDialog.qml")
        }
        MenuItem {
            text: qsTr("&Quitt")
            shortcut: "Ctrl+Q"
            onTriggered: Qt.quit()
        }
    }
    Menu {
        title: qsTr("&Edit")
        MenuItem {
            id: undo
            text: qsTr("&undo");
            onTriggered: viewController.undo()
            shortcut: "Ctrl+Z"
        }
        MenuItem {
            id: redo
            text: qsTr("&redo");
            onTriggered: viewController.redo()
        }
        MenuItem {
            id: options
            text: qsTr("&preferences");
            shortcut: "ctrl + ,"
            onTriggered: dialogLoader.open("qrc:/qml/Dialogs/ConfigurationPanel.qml")
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

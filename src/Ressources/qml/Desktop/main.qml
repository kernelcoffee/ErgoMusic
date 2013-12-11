import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

import "qrc:/qml/Desktop/Widgets"
import "qrc:/qml/Desktop/MenuBar"
import "qrc:/qml/Desktop/StatusBar"
import "qrc:/qml/Desktop/TopBar"
import "qrc:/qml/Desktop/Windows/"


ApplicationWindow {
    id: mainWindow
    width: 800
    height: 600

    minimumWidth: 800
    minimumHeight: 500

    title: "ErgoMusic"

    Behavior on opacity {NumberAnimation {duration: 100}}

    menuBar:  MenuWidget{ id: menuWidget}
    statusBar: StatusWidget {id: statusWidget}

    QtObject {
        id: mainObject

        property variant mainModel: cores.media.library();
    }

    TopWidget {
        id: topWidget
        width: parent.width
    }

    Settings{
        id: settingsWindow
    }

    // DEBUG
    ListModel {
        id: sidebarMenuModel

        ListElement {
            name: "Library"
        }
        ListElement {
            name: "Devices"
        }
        ListElement {
            name: "Playlists"
        }
    }

    ListModel {
        id: testSidebarModel

        ListElement {
            name: "Music"
        }
        ListElement {
            name: "Movies"
        }
        ListElement {
            name: "Podcasts"
        }
    }


    //TODO : move to a separate file
    Component {
        id: sidebarSubmenuDelegate
        Item {
            height: label.height
            width: parent.width
            Text {
                id: label
                text: name
                font.weight: Font.Light
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("whatchPlaylist " + index + "selected");
                }
            }
        }
    }


    SplitView {
        id: mainWidget
        orientation: Qt.Horizontal
        height: mainWindow.height - topWidget.height
        width: mainWindow.width
        anchors.top: topWidget.bottom

        ScrollView {
            id: sidebarMenu
            width: 200
            height: parent.height
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
            frameVisible: false

            Column {
                height: sidebarMenu.height
                width: sidebarMenu.width
                spacing: 10

                CollapsiblePanel {
                    title: "Library"
                    width: parent.width
                    model: testSidebarModel
                    delegate: sidebarSubmenuDelegate
                }
                CollapsiblePanel {
                    width: parent.width
                    title: "Devices"
                    model: sidebarMenuModel
                    delegate: sidebarSubmenuDelegate
                }
                CollapsiblePanel {
                    width: parent.width
                    title: "Playlists"
                    model: watchPlaylistsModel
                    delegate: sidebarSubmenuDelegate
                }
            }
        }
        Loader {
            id: centerItem
            Layout.fillWidth: true
            source: "Mainview/mainListView.qml"
        }
    }
}

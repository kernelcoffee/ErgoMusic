import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

import "qrc:/qml/Desktop/Widgets"

ApplicationWindow {
    id: mainWindow
    width: 800
    height: 600

    minimumWidth: 800
    minimumHeight: 600

    visible: true

    title: "ErgoMusic"

    //    menuBar: MenuWidget{ id: menuWidget}

    Item {
        id: topWidget
        width: mainWindow.width
        height: 80

        Rectangle {
            anchors.fill: parent
            color: "lightsteelblue"
        }
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
            Text {
                id: label
                text: name
                font.weight: Font.Light
            }
        }
    }


    SplitView {
        id: mainWidget
        orientation: Qt.Horizontal
        height: mainWindow.height - topWidget.height - bottomWidget.height
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
                        model: testSidebarModel
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

    Item {
        id: bottomWidget

        width: mainWindow.width
        height: 30
        anchors.top: mainWidget.bottom
        Rectangle {
            anchors.fill: parent
            color: "red"
        }
    }
}

import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import ErgoMusic 1.0

import "Delegates"
import "Menus"

ScrollView {
    id: sideMenu
    frameVisible: false

    property MediaController media
    property ViewController view

    Column {
        id: sideMenuContainer
        width: sideMenu.width
        spacing: 10

        CollapsiblePanel {
            title: qsTr("Library")
            model: ListModel {
                ListElement {
                    name: "Music"
                    status: false
                }
            }
            delegate: SubMenuDelegate {}
        }

        CollapsiblePanel {
            title: qsTr("WatchPlaylists")
            model: media.watchPlaylistsModel
            focus: viewController
            delegate: SubMenuDelegate {
                contextmenu: "qrc:/qml/SideMenu/Menus/WatchPlaylistMenu.qml"
            }
        }
    }
}

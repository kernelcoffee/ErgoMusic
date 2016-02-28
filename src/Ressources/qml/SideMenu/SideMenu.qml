import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.3

import "Delegates"
import "Menus"

ScrollView {
    id: sideMenu
    frameVisible: false

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
            model: watchPlaylistsMenuModel
            delegate: SubMenuDelegate {
                contextmenu: "qrc:/qml/SideMenu/Menus/WatchPlaylistMenu.qml"
            }
        }
    }
}

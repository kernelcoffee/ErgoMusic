import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

import Qt.labs.settings 1.0

import "StatusBar"
import "MenuBar"
import "SideMenu"
import "TopBar"
import "Views"

ApplicationWindow {
    id: root
    title: Qt.application.name
    minimumWidth: 800
    minimumHeight: 600
    width: minimumWidth
    height: minimumHeight
    visible: true

    menuBar: MenuWidget { id: menuWidget }
    statusBar: StatusWidget{ id: statusWidget }

    Settings {
        id: settings
        property alias x: root.x
        property alias y: root.y
        property alias width: root.width
        property alias height: root.height
        property alias visibility: root.visibility
        property alias sideMenuWidth: sideMenu.width
    }

    Loader {
        id: dialogLoader
        function open(path) {
            dialogLoader.source = path
            dialogLoader.item.visible = true
        }
        function popup(path, arguments) {
            dialogLoader.setSource(path, arguments)
            dialogLoader.item.popup()
        }
    }

    TopBar { id: topWidget }

    SplitView {
        id: mainView
        anchors.top: topWidget.bottom
        orientation: Qt.Horizontal
        height: root.height - topWidget.height - statusWidget.height
        width: parent.width

        SideMenu {
            id: sideMenu
            width: 300
            height: parent.height
            Layout.minimumWidth: 200
            Layout.maximumWidth: 400

            media: uiCore.mediaController
        }

        CentralView {
            id: mainWindow
            Layout.fillWidth: true
        }
    }
}

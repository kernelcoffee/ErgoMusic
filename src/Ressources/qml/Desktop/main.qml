import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

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

        SplitView {
            id: mainWidget
            orientation: Qt.Horizontal
            height: mainWindow.height - topWidget.height - bottomWidget.height
            width: mainWindow.width
            anchors.top: topWidget.bottom

            ScrollView {
                width: 200
                Layout.minimumWidth: 150
                Layout.maximumWidth: 300
                frameVisible: false
                ListView {
                    anchors.fill: parent
                    model: 100
                    delegate: Rectangle {
                        height: 20
                        width: parent.width
                        border.width: 1
                        border.color: "black"
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
            height: 40
            anchors.top: mainWidget.bottom
            Rectangle {
                anchors.fill: parent
                color: "red"
            }
        }
}

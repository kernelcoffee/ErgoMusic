import QtQuick 2.8
import QtQuick.Controls 1.4
import ErgoMusic 1.0

Item {
    id: sideMenuDelegate
    height: label.height
    width: parent.width
    enabled: !status

    property string contextmenu
    property MediaController media

    Label {
        id: label
        text: name
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    BusyIndicator {
        id: busyIndicator
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        height: parent.height
        running: status
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            if (mouse.button & Qt.RightButton) {
                dialogLoader.popup(contextmenu, {index: index})
            } else {
                uiCore.viewController.setTrackModel(type, index);
            }
        }
    }
}

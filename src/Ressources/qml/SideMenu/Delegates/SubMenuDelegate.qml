import QtQuick 2.4
import QtQuick.Controls 1.2

Item {
    id: sideMenuDelegate
    height: label.height
    width: parent.width
    enabled: !status

    property string contextmenu

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
            }
            else
                viewController.setTrackModel(type, index);
        }
    }
}

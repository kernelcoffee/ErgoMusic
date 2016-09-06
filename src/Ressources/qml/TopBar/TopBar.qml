import QtQuick 2.4
import QtQuick.Controls 1.2

Item {
    id: topBar
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right

    height: 60

    Item {
        id: controls
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: height * 2.5
        Label {anchors.centerIn: parent; text: "controls"}
    }
    Item {
        id: volume
        anchors.left: controls.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.width * .06
        Label {anchors.centerIn: parent; text: "Volume"}
    }

    Rectangle {
        id: playerScreen
        anchors.centerIn: parent
        width: parent.width / 2.5
        height: parent.height * 0.8
        color: "transparent"
        radius: 4.0
        border.width: 1
        border.color: "grey"
    }


    Rectangle {
        id: searchWrapper
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width * .2
        height: searchField.height * 1.2
        radius: height * .5
        color: "transparent"
        border.width: 1
        border.color: "grey"

        TextEdit {
            id: searchField
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 5
        }
    }
}


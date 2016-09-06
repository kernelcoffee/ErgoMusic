import QtQuick 2.7
import QtQuick.Controls 1.4

StatusBar {
    height: 30

    Row {
        id: leftRow
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        height: parent.height
        Button {
            text: "+"
        }
    }

    Row {
        id: middleRow
        anchors.centerIn: parent
        height: parent.height

    }
}


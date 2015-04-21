import QtQuick 2.4
import QtQuick.Controls 1.2

StatusBar {
    height: 30
    Row {
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        height: parent.height
        Button {
            text: "+"
        }
    }
}


import QtQuick 2.1
import QtQuick.Controls 1.0


ApplicationWindow {
    id: mainWindow

    width: 800
    height: 600


    Rectangle {
        id: test
        anchors.fill: parent
        color: "blue"
    }

    Component.onCompleted: console.log("toto - " + mainWindow.width + "x" + mainWindow.height)
}

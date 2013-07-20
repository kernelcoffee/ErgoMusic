import QtQuick 2.1
import QtQuick.Controls 1.0

StatusBar {
    id: statusBar
    height: 30
    opacity: 0
    Component.onCompleted: opacity = 1
    Behavior on opacity {NumberAnimation {duration: 200}}

}

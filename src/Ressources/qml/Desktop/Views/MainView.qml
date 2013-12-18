import QtQuick 2.1
import QtQuick.Controls 1.0
import ErgoMusic 1.0
import "qrc:/qml/Desktop/Views/"

CentralView {
    id: mainView

    Component {
        id: listViewComponent
        MainListView {
            id: listView
        }
    }

    Loader {
        id: centerItem
        anchors.fill: parent
        sourceComponent: listViewComponent
    }

    states: [
        State {name: "songList"
            PropertyChanges {target: centerItem; sourceComponent: listViewComponent}
        }
    ]
}

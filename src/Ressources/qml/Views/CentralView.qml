import QtQuick 2.0

Item {
    Loader {
        anchors.fill: parent
        sourceComponent: listViewComponent

        Component {
            id: listViewComponent
            MainListView { id: listView }
        }
    }
}


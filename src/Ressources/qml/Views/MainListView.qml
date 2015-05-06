import QtQuick 2.4
import QtQuick.Controls 1.2

TableView {
    id: mainListView
    model: viewController.trackModel
    sortIndicatorVisible: true
    selectionMode: SelectionMode.ExtendedSelection

    onSortIndicatorOrderChanged: console.log(sortIndicatorOrder +  " " + sortIndicatorColumn)
    onSortIndicatorColumnChanged: console.log(sortIndicatorOrder +  " " + sortIndicatorColumn)

    TableViewColumn{ role: "index" ; title: ""; width: 40}
    TableViewColumn{ role: "title"  ; title: "Title" ; width: 200 }
    TableViewColumn{ role: "artist" ; title: "Artist" ; width: 200 }

    itemDelegate: Item {
        Label {
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            color: styleData.textColor
            elide: styleData.elideMode
            text: styleData.value
        }
    }
}

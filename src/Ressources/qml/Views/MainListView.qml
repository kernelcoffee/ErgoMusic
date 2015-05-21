import QtQuick 2.4
import QtQuick.Controls 1.2

TableView {
    id: mainListView
    model: viewController.trackSortModel
    sortIndicatorVisible: true
    selectionMode: SelectionMode.ExtendedSelection

    onSortIndicatorOrderChanged: model.sort(sortIndicatorColumn, sortIndicatorOrder)
    onSortIndicatorColumnChanged: mode.sort(sortIndicatorColumn, sortIndicatorOrder)

    TableViewColumn{ role: "index" ; title: ""; width: 40}
    TableViewColumn{ role: "title"  ; title: "Title" ; width: 200 }
    TableViewColumn{ role: "artist" ; title: "Artist" ; width: 200 }
    TableViewColumn{ role: "album" ; title: "Album" ; width: 200 }
    TableViewColumn{ role: "length" ; title: "Length" ; width: 200 }
    TableViewColumn{ role: "genre" ; title: "genre" ; width: 200 }
    TableViewColumn{ role: "track" ; title: "track" ; width: 200 }

    itemDelegate: Item {
        Label {
            id: itemLabel
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            elide: styleData.elideMode
            text: styleData.value
        }
    }
}

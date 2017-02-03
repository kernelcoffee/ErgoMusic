import QtQuick 2.8
import QtQuick.Controls 1.5

TableView {
    id: mainListView
    model: uiCore.viewController.trackSortModel
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

    onDoubleClicked: {
        console.log("double click " + currentRow)
//        uiCore.mediaController.play(
//                    uiCore.viewController.selectedType,
//                    uiCore.viewController.selectedIndex,
//                    currentRow)
    }

    //    itemDelegate: Item {
    //        Label {
    //            id: itemLabel
    //            anchors.verticalCenter: parent.verticalCenter
    //            width: parent.width
    //            elide: styleData.elideMode
    //            text: styleData.value
    //        }
    //    }
}

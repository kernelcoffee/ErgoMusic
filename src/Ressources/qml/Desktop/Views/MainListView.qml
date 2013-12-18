import QtQuick 2.1
import QtQuick.Controls 1.0

TableView {
    id: mainListView
    model: mainView.model
    TableViewColumn{ role: " "  ; title: " " ; width: 20 }
    TableViewColumn{ role: "title"  ; title: "Title" ; width: 200 }
    TableViewColumn{ role: "author" ; title: "Author" ; width: 200 }

    itemDelegate: Item {
        Text {
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width
            color: styleData.textColor
            elide: styleData.elideMode
            text: styleData.value
        }
    }

    onDoubleClicked: {
        console.log("double click " + row)
        model.select(row);
    }
}

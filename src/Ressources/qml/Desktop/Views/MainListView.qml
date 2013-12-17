import QtQuick 2.1
import QtQuick.Controls 1.0

TableView {
    id: mainListView
    model: mainView.model
    onModelChanged: model + " " + mainView.model
    TableViewColumn{ role: "title"  ; title: "Title" ; width: 100 }
    TableViewColumn{ role: "author" ; title: "Author" ; width: 200 }
}

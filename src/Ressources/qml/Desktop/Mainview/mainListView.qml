import QtQuick 2.1
import QtQuick.Controls 1.0

TableView {
    width: 100
    height: 62
    TableViewColumn{ role: "title"  ; title: "Title" ; width: 100 }
    TableViewColumn{ role: "author" ; title: "Author" ; width: 200 }
}

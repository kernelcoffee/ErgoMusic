import QtQuick 2.1
import QtQuick.Controls 1.0

MenuBar {
    id: menuWidget
    Menu {
        title: "File"
        MenuItem { text: "Open..." }
        MenuItem { text: "Close" }
    }

    Menu {
        title: "Edit"
        MenuItem { text: "Cut" }
        MenuItem { text: "Copy" }
        MenuItem { text: "Paste" }
    }
}

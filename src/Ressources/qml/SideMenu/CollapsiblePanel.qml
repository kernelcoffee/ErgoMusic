import QtQuick 2.4
import QtQuick.Controls 1.2

Item {
    id: collapsiblePanel
    anchors.left: parent.left
    anchors.right: parent.right
    height: titleItem.height + listView.contentHeight

    signal itemselected(int index)

    property alias title: titleTxt.text
    property alias model: listView.model
    property alias delegate: listView.delegate

    Item {
        id: titleItem
        height: titleTxt.height
        width: parent.width
        anchors.right: parent.right
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: titleTxt
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            font.capitalization: Font.SmallCaps
            font.weight: Font.Black
            font.pointSize: 12
        }

        Label {
            id: titleHide
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            text: "hide"
            font.pointSize: 10
            opacity: 0

            Behavior on opacity { NumberAnimation {duration: 200}}
        }

        MouseArea {
            id: titleMA
            anchors.fill: parent
            onEntered: titleHide.opacity = 1
            onExited: titleHide.opacity = 0
            hoverEnabled: true

            onClicked: {
                if (collapsiblePanel.state == "collapsed") {
                    collapsiblePanel.state = ""
                } else {
                    collapsiblePanel.state = "collapsed"
                }
            }
        }
    }

    ListView{
        id: listView
        leftMargin: 10
        width: parent.width
        height: childrenRect.height
        anchors.top: titleItem.bottom
        interactive: false
        highlight: highlightBar
    }

    Component {
        id: highlightBar
        Rectangle {
            width: 200; height: 50
            color: "#FFFF88"
            y: listView.currentItem.y;
            Behavior on y { SpringAnimation { spring: 2; damping: 0.1 } }
        }
    }


    states: [
        State {
            name: "collapsed"
            PropertyChanges { target: listView; height: 0; opacity: 0 }
            PropertyChanges { target: collapsiblePanel; height: titleItem.height }
            PropertyChanges { target: titleHide; text: "show" }
        }
    ]

    transitions: [
        Transition {
            NumberAnimation { target: listView; property: "height"; duration: 130 }
            NumberAnimation { target: collapsiblePanel; property: "height"; duration: 130 }
            NumberAnimation { target: listView; property: "opacity"; duration: 130 }
        }
    ]
}

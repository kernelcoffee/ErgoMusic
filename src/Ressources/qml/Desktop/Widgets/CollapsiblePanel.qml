import QtQuick 2.1

Item{
    id: collapsiblePanel

    signal itemselected(int index)

    property alias title: titleTxt.text
    property alias model: listView.model
    property alias delegate: listView.delegate


    Item{
        id: titleRect
        width: parent.width - 10
        height: titleTxt.height
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: titleTxt
            font.capitalization: Font.SmallCaps
            font.weight: Font.Black
            font.pointSize: 15
        }
        Text {
            id: titleHide
            height: contentHeight
            width: contentWidth
            anchors.right: titleRect.right
            anchors.rightMargin: 5
            text: "hide"
            font.pointSize: 11
            opacity: 0

            Behavior on opacity { NumberAnimation {duration: 150}}
        }
        MouseArea{
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
        height: parent.height - titleRect.height
        anchors.top: titleRect.bottom
        interactive: false
        model: customModel
        delegate: customDelegate
    }

    states: [
        State {
            name: "collapsed"
            PropertyChanges { target: listView; height: 0; opacity: 0 }
            PropertyChanges { target: collapsiblePanel; height: titleRect.height }
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

    Component.onCompleted:  {
        collapsiblePanel.height = titleRect.height+listView.contentHeight
    }
}

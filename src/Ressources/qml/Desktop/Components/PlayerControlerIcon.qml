import QtQuick 2.1
import QtGraphicalEffects 1.0


Item {
    id: playerControlerIcon

    property alias source: icon.source
    property alias sourceSize: icon.sourceSize

    signal clicked()
    signal pressed()
    signal released()

    Image {
        id: icon
        sourceSize.height: parent.height
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
    }

    MouseArea {
        anchors.fill: parent
        onClicked: playerControlerIcon.clicked()
        onPressed: shadow.color = "#000"
        onReleased:  {
            playerControlerIcon.released()
            shadow.color = "#aaa"
        }
        onPressAndHold: playerControlerIcon.pressed()
    }

    InnerShadow {
        id: shadow
        anchors.fill: playerControlerIcon
        radius: icon.height * 1
        samples: 32
        spread: 0.1
        color: "#aaa"
        source: icon
    }

//    Glow {
//        id: glow
//        anchors.fill: playerControlerIcon
//        opacity: 0
//        radius: 1
//        samples: 32
//        color: "#6FC3DF"
//        source: icon
//    }

    //    LinearGradient {
    //        anchors.fill: parent
    //        source: Image { source: playerControlerIcon.source }
    //        start: Qt.point(0, 0)
    //        end: Qt.point(0, 300)
    //        gradient: Gradient {
    //            GradientStop { position: 0.0; color: "#CCCCCC" }
    //            GradientStop { position: 1.0; color: "#808080" }
    //        }
    //    }


//    Rectangle {
//        id: filter
//        anchors.fill: parent
//        color: "black"
//        opacity: .1
//    }
}

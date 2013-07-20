import QtQuick 2.1
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.0

import "qrc:/qml/Desktop/Components"

Item {
    id: topWidget
    height: 60

    Row {
        id: controlWrapper
        height: parent.height * 0.6
        width: parent.height * 2.3
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 20
        spacing: 10

        PlayerControlerIcon {
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height * 0.6
            width: parent.width * 0.3
            source: "qrc:/images/images/playerControls/previous.svg"
            onClicked: console.log("previous click")
            onPressed: console.log("fast baskward")
            onReleased: console.log("release")
        }
        PlayerControlerIcon {
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height
            width: parent.width * 0.3
            source: "qrc:/images/images/playerControls/play.svg"
            onClicked: console.log("play click")
        }
        PlayerControlerIcon {
            anchors.verticalCenter: parent.verticalCenter
            height: parent.height * 0.6
            width: parent.width * 0.3
            source: "qrc:/images/images/playerControls/next.svg"
            onClicked: console.log("play click")
            onPressed: console.log("fast forward")
            onReleased: console.log("release")
        }
    }

    Slider {
        id: volumeSlider
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: controlWrapper.right
        anchors.leftMargin: 20
        width: parent.width * .06
        onValueChanged: {
            searchInnerShadow.radius = 16 * value
            console.log(value + " " + searchInnerShadow.radius)
        }
    }

    Rectangle {
        id: playerScreen
        anchors.centerIn: parent
        width: parent.width / 2.5
        height: parent.height * 0.8
        radius: 4.0

//        InnerShadow {
//            anchors.fill: playerScreen
//            radius: 20.0
//            samples: 16
//            color: "#000"
//            source: playerScreen
//        }
    }

    Rectangle {
        id: searchWrapper
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width * .2
        height: searchField.height * 1.2
        radius: 10
        Image {
            id: searchIcon
            width: parent.height
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/images/playerControls/play.svg"
        }

        TextEdit {
            id: searchField
            anchors.right: parent.right
            anchors.left: searchIcon.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 10

        }
        InnerShadow {
            id: searchInnerShadow
            anchors.fill: parent
            radius: 8.0
            samples: 24
            color: "#000"
            source: parent
        }
    }
}

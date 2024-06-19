// The button of the start screen. There would be an icon on the middle of
// the button, and a line of text beneath it.

import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Shapes 1.15

Rectangle {
    id: buttonStartScreen
    property alias imageUrl: icon.source
    property alias text: label.text

    color: "white"
    width: 120
    height: 120
    radius: 20
    border.color: "black"
    border.width: 3

    signal clicked

    Image {
        id: icon
        anchors.horizontalCenter: parent.horizontalCenter
        y: 20
        width: 45
        height: 45
        smooth: true
    }

    Text {
        id: label
        anchors.horizontalCenter: parent.horizontalCenter
        y: 75
        color: "black"
        font.family: "黑体"
        font.pixelSize: 25
    }

    MouseArea {
        anchors.fill: parent
        onEntered: {
            buttonStartScreen.state = "hovered"
        }
        onExited: {
            buttonStartScreen.state = ""
        }

        onClicked: {
            buttonStartScreen.clicked
        }
    }

    // The state that the mouse is on the button.
    states: [
        State {
            name: "hovered"
            PropertyChanges {
                target: buttonStartScreen
                color: "#ecf0f1"
            }
        }
    ]

    transitions: [
        Transition {
            from: "*"
            to: "hovered"
            reversible: true
            ColorAnimation {
                duration: 400
            }
        }
    ]

    Behavior on color {
        ColorAnimation {
            duration: 400
        }
    }
}

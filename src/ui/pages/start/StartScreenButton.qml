// The button of the start screen. There would be an icon on the middle of
// the button, and a line of text beneath it.

import QtQuick
import QtQuick.Layouts
import QtQuick.Shapes

Rectangle{
    id: buttonStartScreen
    property alias imageUrl: icon.source
    property alias text: label.text

    color: "white"
    width: 120
    height: 120
    radius: 20
    border.color: "black"
    border.width: 3

    Image{
        id: icon
        anchors.horizontalCenter: parent.horizontalCenter
        y: 20
        width: 45
        height: 45
        smooth: true
    }

    Text{
        id: label
        anchors.horizontalCenter: parent.horizontalCenter
        y: 75
        color: "black"
        font.family: "黑体"
        font.pixelSize: 25
    }

    MouseArea{
        anchors.fill: parent
        onEntered: {
            parent.state = "hovered"
        }
        onExited: {
            parent.state = ""
        }

        onClicked: {
            // TODO: Mouse event.
        }
    }

    // The state that the mouse is on the button.
    states: [
        State{
            name: "hoverd"
            PropertyChanges{
                target: buttonStartScreen
                color: "#bababa"
            }
        }
    ]

    transitions: [
        Transition {
            from: "*"
            to: "hoverd"
            reversible: true

            ColorAnimation{
                duration: 400
            }
        }
    ]
}
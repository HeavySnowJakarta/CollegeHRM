// This file defines the titlebar of the program.

import QtQuick
import QtQuick.Window

Rectangle{
    id: titleBar
    width: parent.width
    color: "white"

    property string titleText: title.text
    property int titleSize: title.font.pixelSize
    property bool showMinimizeButton: minimizeButton.visible

    // The title of the title bar, standing on the left.
    Text{
        anchors.verticalCentor: parent.verticalCentor
        anchors.left: parent.left
        id: title
        height: parent.height
        color: "black"
    }

    // Area to drag the window.
    MouseArea{
        id: titleBarMouseArea
        anchors.fill: parent
        drag.target: window
    }

    // The button to close.
    Rectangle{
        id: closeButton
        height: parent.height
        width: parent.height
        anchors.right: parent.right
        color: "white"
        onClicked: Qt.quit()

        Image{
            height: (parent.height)/3
            width: (parent.width)/3
            anchors.centerIn: parent
            color: "black"

            source: "qrc:/assets/icons/x.svg"
        }
    }

    // The button to minimize.
    Rectangle{
        id: minimizeButton
        height: parent.height
        width: parent.height
        anchors.right: closeButton.left
        color: "white"
        // onClicked:

        Image{
            height: (parent.height)/3
            width: (parent.width)/3
            anchors.centerIn: parent
            color: "black"

            source: "qrc:/assets/icons/dash.svg"
        }
    }
}
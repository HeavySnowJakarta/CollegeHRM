// This file defines the titlebar of the program.

import QtQuick
import QtQuick.Window

Rectangle{
    id: titleBar
    color: "white"

    property alias titleText: title.text
    property alias titleSize: title.font.pixelSize
    property alias showMinimizeButton: minimizeButton.visible
    property var window: null

    // The title of the title bar, standing on the left.
    Text{
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        id: title
        height: parent.height
        color: "black"
    }

    // Area to drag the window.
    MouseArea{
        id: titleBarMouseArea
        anchors.fill: parent
        drag.target: titleBar  // Use the titleBar itself as the drag target
        onReleased: {
            if (appWindow) {
                appWindow.x += dragX;
                appWindow.y += dragY;
            }
        }
    }

    // The button to close.
    Rectangle{
        id: closeButton
        height: parent.height
        width: parent.height
        anchors.right: parent.right
        color: "white"

        Image{
            height: (parent.height)/3
            width: (parent.width)/3
            anchors.centerIn: parent

            source: "qrc:/assets/icons/x.svg"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: Qt.quit()
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

            source: "qrc:/assets/icons/dash.svg"
        }
    }
}
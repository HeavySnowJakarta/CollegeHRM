import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow{
    id: startWindow
    visible: true

    width: 500
    height: 240 // 300 for custom title bar.
    color: "white"

    // flags: Qt.FramelessWindowHint
    title: "College Human Resource Manager"


    // The title bar.
    Rectangle{
        visible: false
        id: titleBar
        color: "yellow"
        height: 60
        width: parent.width

        anchors.left: parent.left

        // TODO: Usage of custom title bar.
    }

    // The two buttons.
    StartScreenButton{
        id: newDatabaseButton
        x: 106
        y: 40 // 100 for custom titlebar.

        text: "New"
        imageUrl: "qrc:/assets/icons/plus-circle.svg"

        onClicked{
            // See `src/lib/frontend/startup.cpp::StartupManager::create()`.
            startupManager.create()
        }
    }

    StartScreenButton{
        id: openDatabaseButton
        x: 273
        y: 40 // 100 for custom titlebar.

        text: "Open"
        imageUrl: "qrc:/assets/icons/folder.svg"

        onClicked{
            // See `src/lib/frontend/startup.cpp::StartupManager::open()`.
            startupManager.open()
        }
    }
}
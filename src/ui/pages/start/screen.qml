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
}
import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow{
    visible: true
    width: 500
    height: 300
    color: "white"

    flags: Qt.FramelessWindowHint
    title: "College Human Resource Manager"

    // The title bar.
    Rectangle{
        id: titleBar
        color: "red"
        source: "qrc:/ui/components/titlebar.qml"
        height: 60
        showMinimizeButton: false
        titleText: "College Human Resource Manager"

        anchors.left: parent.left
    }
}
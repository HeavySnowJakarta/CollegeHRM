import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow{
    visible: true
    width: 500
    height: 300
    color: "white"

    //flags: Qt.FramelessWindowHint
    title: "College Human Resource Manager"

    // The title bar.
    Rectangle{
        id: titleBar
        color: "red"
        height: 60

        anchors.left: parent.left

        Component.onCompleted: {
            var component = Qt.createComponent("qrc:ui/components/titlebar.qml")
            if (component.status == Component.Ready){
                var titleBar = component.createObject(titleBar)
                titleBar.titleText = "College Human Resource Manager"
                titleBar.showMinimizeButton = false
            }
            else{
                console.error(
                    "Error loading titleBar component: ",
                    component.errorString()
                )
            }
        }
    }
}
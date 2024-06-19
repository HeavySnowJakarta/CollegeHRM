import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Shapes 1.15

Rectangle{
    id: operateWindow
    visible: true

    height: 600
    width: 1000
    color: "white"
    property string title: "Database"

    // Stat area, on the right section.
    Rectangle{
        id: statArea

        width: 350
        anchors.right: parent.right
        color: "green"
    }

    // Four areas of the operation window.
    // Operation area, on the top corner on the left hand.
    Rectangle{
        id: operationArea

        height: 100
        anchors.left: parent.left
        anchors.right: statArea.left
        color: "blue"
    }

    // Search area, beneath the operation area.
    Rectangle{
        id: searchArea

        height: 40
        width: operationArea.width
        anchors.top: operationArea.bottom
        color: "red"
    }

    // Table area, beneath the search area.
    Rectangle{
        id: tableArea

        width: operationArea.width
        anchors.top: searchArea.bottom
        anchors.bottom: parent.bottom
        color: "yellow"
    }
}
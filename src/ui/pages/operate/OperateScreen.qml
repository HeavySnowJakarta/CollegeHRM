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

        // There are two buttons of this area: new and delete.

        // New.
        Rectangle{
            id: newOperation

            x: 30
            anchors.verticalCenter: parent.verticalCenter
            height: 60
            width: 60
            color: "white"

            Image{
                anchors.centerIn: parent
                source: "qrc:/assets/icons/plus.svg"
                height: 40
                width: 40
            }

            MouseArea{
                anchors.fill: parent
            }
        }

        // Delete.
        Rectangle{
            id: deleteOperation

            anchors.left: newOperation.right
            anchors.verticalCenter: parent.verticalCenter
            height: 60
            width: 60
            color: "white"

            Image{
                anchors.centerIn: parent
                source: "qrc:/assets/icons/trash.svg"
                height: 30
                width: 30
            }
        }
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
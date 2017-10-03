import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Rectangles")

    Rectangle {
        color: "red"
        anchors.fill: parent
        MouseArea {
            anchors.fill: parent
            onPressed: console.log("Outer rectangle pressed")
        }
        Rectangle {
            color: "green"
            width: parent.width - 5
            height: parent.height - 5
            anchors.centerIn: parent
            MouseArea {
                anchors.fill: parent
            }
        }
    }
}

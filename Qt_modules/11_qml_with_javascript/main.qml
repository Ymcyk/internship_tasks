import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    minimumHeight: 150
    minimumWidth: 150
    title: qsTr("Rectangle area")

    Rectangle {
        anchors.fill: parent
        color: "green"

        function area(height, width) {
            return height * width;
        }

        Text {
            id: text
            text: parent.area(parent.height, parent.width)
            anchors.centerIn: parent
            color: "white"
        }

        Text {
            id: height
            text: parent.height
            rotation: 90
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
        }

        Text {
            id: width
            text: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }
    }
}

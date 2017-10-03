import QtQuick 2.0

Rectangle {
    color: "white"
    width: radius * 2
    height: radius * 2
    border.color: black
    border.width: 5
    Rectangle {
        anchors.centerIn: parent
        height: parent.height
        width: 5
        color: "grey"
    }
    Rectangle {
        anchors.centerIn: parent
        height: 5
        width: parent.width
        color: "grey"
    }
}

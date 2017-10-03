import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

import "main.js" as JS

Window {
    id: mainWindow
    visible: true
    width: 300
    height: 300
    minimumHeight: 300
    minimumWidth: 300
    title: qsTr("QML basics")

    Loader {
        id: loader
        anchors.fill: parent

        states: [
            State {
                name: "rectangles"
                PropertyChanges {
                    target: loader
                    source: "RectPage.qml"
                }
            },
            State {
                name: "image"
                PropertyChanges {
                    target: loader
                    source: "ImagePage.qml"
                }
            }
        ]

        Component.onCompleted: loader.state = "rectangles";
    }

    Rectangle {
        width: 80; height: 30
        color: "white"
        border.width: 1
        border.color: "black"

        Text {
            text: loader.state === "rectangles" ? "Image" : "Rectangles";

            anchors.centerIn: parent
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                if (loader.state === "rectangles") {
                    loader.state = "image";
                } else {
                    loader.state = "rectangles";
                }
            }
        }
    }
}

import QtQuick 2.6
import QtQuick.Window 2.2

import "main.js" as JS

Window {
    id: mainWindow
    visible: true
    width: 600
    height: width
    maximumHeight: height
    minimumHeight: height
    maximumWidth: width
    minimumWidth: width
    title: qsTr("QML basics")


    Component {
        id: rectButton

        Rectangle {
            property int buttonId
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            height: parent.height / 3
            width: parent.width / 3

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked: {
                    if (parent.buttonId === 4) {
                        JS.changeAll();
                    } else {
                        JS.changeClockwise(parent.buttonId);
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        JS.createRectangles();
    }
}

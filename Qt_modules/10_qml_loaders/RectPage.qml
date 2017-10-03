import QtQuick 2.0
import QtQuick.Layouts 1.3

import "main.js" as JS

GridLayout {
    id: grid
    anchors.fill: parent
    columns: 3
    rows: 4

    Repeater {
        id: repeater
        model: 9
        Rectangle {
            property int buttonId

            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            Layout.fillHeight: true
            Layout.fillWidth: true

            buttonId: index

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked: {
                    if (parent.buttonId === 4) {
                        JS.changeAll();
                    } else {
                        JS.changeClockwise();
                    }
                }
            }
        }
    }
}

import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import "counter.js" as Counter

Window {
    id: mainWindow
    visible: true
    width: 600
    height: 150
    minimumHeight: height
    maximumHeight: height
    minimumWidth: width
    maximumWidth: width
    title: qsTr("Bouncing wheel")

    ColumnLayout {
        anchors.fill: parent
        Wheel {
            id: wheel
            radius: 25

            ParallelAnimation {
                id: rootAnim
                running: true
                RotationAnimation {
                    id: wheelRotation
                    loops: Animation.Infinite
                    target: wheel
                    from: 0
                    to: 360
                    duration: 1000
                }
                SequentialAnimation {
                    loops: Animation.Infinite
                    PropertyAnimation {
                        target: wheel
                        property: "x"
                        from: 0
                        to: mainWindow.width - wheel.width
                        duration: 1000
                    }
                    PropertyAnimation {
                        target: wheel
                        property: "x"
                        from: mainWindow.width - wheel.width
                        to: 0
                        duration: 1000
                    }
                }
            }
        }
        RowLayout {
            Layout.fillWidth: true
            Button {

                text: Counter.getDescription()
                onPressed: {
                    Counter.buttonPressed();
                    text = Counter.getDescription();
                }
            }
            Slider {
                Layout.fillWidth: true
                onValueChanged: {
                    rootAnim.stop();
                    wheelRotation.duration = 1000 - 800 * value;
                    rootAnim.start();
                }
            }
        }
    }
}

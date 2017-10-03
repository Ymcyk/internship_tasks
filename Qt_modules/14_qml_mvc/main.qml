import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    minimumWidth: 500
    minimumHeight: 200
    title: qsTr("Animal List")

    ListModel {
        id: animalsModel

        ListElement {
            name: "Burek"
            species: "Dog"
            age: 12
            legs: 4
            height: 0.5
        }
        ListElement {
            name: "Kuba"
            species: "Guinea pig"
            age: 2
            legs: 4
            height: 0.1
        }
        ListElement {
            name: "Stefan"
            species: "Cat"
            age: 5
            legs: 4
            height: 0.3
        }
    }

    ColumnLayout {
        id: mainLayout

        anchors.centerIn: parent
        anchors.fill: parent

        states: [
            State {
                name: "cpp"
                PropertyChanges {
                    target: animalList
                    model: cppModel
                }
                PropertyChanges {
                    target: button
                    text: "qml model"
                }
            },
            State {
                name: "qml"
                PropertyChanges {
                    target: animalList
                    model: animalsModel
                }
                PropertyChanges {
                    target: button
                    text: "cpp model"
                }
            }
        ]

        AnimalList {
            id: animalList
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: button
            text: "change"
            onPressed: parent.state == "qml" ? parent.state = "cpp" : parent.state = "qml";
        }

        Component.onCompleted: {
            state = "qml";
        }
    }
}

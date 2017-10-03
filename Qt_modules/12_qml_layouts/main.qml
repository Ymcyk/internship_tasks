import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 600
    height: 550
    minimumWidth: 600
    minimumHeight: 550
    title: qsTr("My Qt window") + qmlTranslator.emptyString

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        anchors.topMargin: 20

        GridLayout {
            Layout.fillWidth: true
            columns: 2
            Label {
                text: "%1:".arg(qsTr("Name")) + qmlTranslator.emptyString
            }

            TextField {
                Layout.fillWidth: true
            }

            Label {
                text: "%1:".arg(qsTr("Last name")) + qmlTranslator.emptyString
            }

            TextField {
                Layout.fillWidth: true
            }

            Item {
                Layout.columnSpan: 2
                height: 20
            }

            Label {
                text: "%1:".arg(qsTr("Age")) + qmlTranslator.emptyString
            }

            SpinBox {
                from: 0
                to: 150
            }

            Label {
                text: "%1:".arg(qsTr("Country")) + qmlTranslator.emptyString
            }

            ComboBox {
                textRole: "key"
                model: ListModel {
                    id: countries
                    ListElement { key: qsTr("USA"); value: "en" }
                    ListElement { key: qsTr("Poland"); value: "pl" }
                }

                onCurrentIndexChanged: {
                    qmlTranslator.setTranslation(countries.get(currentIndex).value);
                }
            }
        }

        Connections {
            target: qmlTranslator
            onLanguageChanged: {
                console.log("Language changed");
            }
        }

        function retrlanslate() {

        }

        Item {
            Layout.fillWidth: true
            height: 20
        }

        GroupBox {
            title: "%1:".arg(qsTr("Sports")) + qmlTranslator.emptyString
            GridLayout {
                rows: 4
                columns: 2
                columnSpacing: 150
                Repeater {
                    model: [qsTr("football") + qmlTranslator.emptyString,
                            qsTr("basketball") + qmlTranslator.emptyString,
                            qsTr("hockey") + qmlTranslator.emptyString,
                            qsTr("cricket") + qmlTranslator.emptyString,
                            qsTr("skating") + qmlTranslator.emptyString,
                            qsTr("heavy weight lifting") + qmlTranslator.emptyString,
                            qsTr("swimming") + qmlTranslator.emptyString,
                            qsTr("running") + qmlTranslator.emptyString]
                    CheckBox {
                        text: modelData
                    }
                }
            }
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RowLayout{
            Layout.alignment: "AlignRight"
            Button {
                text: qsTr("OK") + qmlTranslator.emptyString
                onPressed: console.log("OK pressed")
            }
            Button {
                text: qsTr("Cancel") + qmlTranslator.emptyString
                onPressed: Qt.quit()
            }
        }
    }
}

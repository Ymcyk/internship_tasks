import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    property alias model: list.model

    TableView {
        id: list
        anchors.fill: parent
        model: model

        TableViewColumn {
            role: "name"
            title: "Name"
            width: 100
        }
        TableViewColumn {
            role: "species"
            title: "Species"
            width: 100
        }
        TableViewColumn {
            role: "age"
            title: "Age"
            width: 100
        }
        TableViewColumn {
            role: "legs"
            title: "Legs"
            width: 100
        }
        TableViewColumn {
            role: "height"
            title: "Height"
            width: 100
        }
    }
}

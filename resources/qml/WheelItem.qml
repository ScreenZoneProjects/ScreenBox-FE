import QtQuick 2.0

Rectangle {
    id: witemc
    property int baseIndex: -7
    property int index: 0
    property string title: "0"
    color: "red"

    Text {
        text: qsTr(witemc.title)
        color: "white"
        Component.onCompleted: {
            anchors.centerIn = parent
        }
    }
}

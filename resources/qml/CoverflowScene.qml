import QtQuick 2.0
import QuickFrontend 1.0

QuickScene {

    property QuickFrontend frontend
    property QuickSettings settings

    signal switchScene();

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_S:
            switchScene();
            break;
        default:
            break;
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "red"
    }
}

import QtQuick 2.0
import ScreenBox 1.0

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

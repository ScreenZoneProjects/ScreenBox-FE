import QtQuick 2.0
import QuickFrontend 1.0

QuickScene {

    property QuickFrontend frontend
    property QuickSettings settings

    signal switchToGrid();
    signal switchToWheel();

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_G:
            switchToGrid();
            break;
        case Qt.Key_W:
            switchToWheel();
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

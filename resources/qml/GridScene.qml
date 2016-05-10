import QtQuick 2.0
import QuickFrontend 1.0

QuickScene {
    property QuickFrontend frontend
    property QuickSettings settings

    signal switchToCoverFlow();
    signal switchToWheel();

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_W:
            switchToWheel();
            break;
        case Qt.Key_C:
            switchToCoverFlow();
            break;
        default:
            break;
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "#5555AA"
    }
}

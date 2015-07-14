import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    visibility: Window.FullScreen
    color: "transparent"
    flags: Qt.FramelessWindowHint
    title: "ScreenFlow"

    SplashScreen
    {
        anchors.fill: parent
    }
}

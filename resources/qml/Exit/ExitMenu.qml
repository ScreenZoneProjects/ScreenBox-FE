import QtQuick 2.0
import ScreenBox 1.0

Rectangle {
    property string action: "exit"
    property string pointed: "yes"
    property QuickFrontend frontend

    //Behavior on opacity { PropertyAnimation { duration: 0 } }

    onPointedChanged: {
        if (pointed === "yes")
            menuExitArrow.x =
                    (menuExitBackground.width*0.33)-menuExitArrow.width-10
        else
            menuExitArrow.x =
                    (menuExitBackground.width*0.66)-menuExitArrow.width-10
    }

    Image {
        id: menuExitBackground
        anchors.fill: parent
        source: "file:/" + _APP_DIR_ +
                "/Media/Frontend/Images/Menu_Exit_Background.png"
    }

    Image {
        id: questionText
        source: "file:/" + _APP_DIR_ +
                "/Media/Frontend/Images/Text_Exit_WouldYouLikeToExit.png"
        width: parent.width*0.5
        fillMode: Qt.KeepAspectRatio
        anchors.horizontalCenter: parent.horizontalCenter
        y: parent.height*0.4
    }

    Image {
        id: yesText
        source: "file:/" + _APP_DIR_ +
                "/Media/Frontend/Images/Text_Exit_Yes.png"
        fillMode: Qt.KeepAspectRatio
        height: parent.height*0.1
        y: parent.height*0.6
        x: parent.width*0.33
    }

    Image {
        id: noText
        source: "file:/" + _APP_DIR_ + "/Media/Frontend/Images/Text_Exit_No.png"
        fillMode: Qt.KeepAspectRatio
        height: parent.height*0.1
        y: parent.height*0.6
        x: parent.width*0.66

    }

    Image {
        id: menuExitArrow
        fillMode: Qt.KeepAspectRatio
        height: parent.height*0.1
        x: (parent.width*0.33)-menuExitArrow.width-10
        y: parent.height*0.6
        source: "file:/" + _APP_DIR_ +
                "/Media/Frontend/Images/Menu_Exit_Arrow.png"
    }

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_Escape:
            focus = false;
            visible = false;
            break;
        case Qt.Key_Left:
            pointed = "yes"
            break;
        case Qt.Key_Right:
            pointed = "no"
            break;
        case Qt.Key_Return:
            if (pointed === "yes")
                Qt.quit();
            else {
                opacity = 0;
                frontend.currentScene.focus = true;
            }
            break;
        default:
            break;
        }
    }
}

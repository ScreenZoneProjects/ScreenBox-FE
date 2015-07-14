import QtQuick 2.4

Rectangle {
    color: "#00FFFFFF"

    Image {
        id: screenFlowLogo
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter : parent.verticalCenter
        anchors.verticalCenterOffset: 30
        width: parent.height / 2
        height: parent.height / 2
        visible: true
        clip: false
        source: "resources/images/logo.png"

        OpacityAnimator {
            id: fadeIn
            target: screenFlowLogo;
            from: 0;
            to: 1;
            duration: 1000
            easing.type: Easing.InCubic
            running: true
        }


//        SequentialAnimation on y {
//            loops: 6

//            PropertyAnimation{
//                to : 180
//                duration: 500
//                easing.type: Easing.OutQuad
//            }

//            PropertyAnimation {
//                to : 250
//                duration: 500
//                easing.type : Easing.InQuad
//            }
//        }


    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: screenFlowLogo.bottom
        anchors.topMargin: 10
        text: "Loading"
        font.family: ".Helvetica Neue Interface -M3"
        color: "white"
        font.pointSize: 30
    }
}

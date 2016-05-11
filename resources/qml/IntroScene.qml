import QtQuick 2.0
import QtAV 1.6
import QuickFrontend 1.0

QuickScene {
    property QuickSettings settings
    property MediaPlayer videoPlayer

    NumberAnimation {
        id: fadeIn;
        from: 0;
        to: 1;
        duration: 1000;
        target: introOutput;
        property: "opacity"
    }

    Component.onCompleted: {
        if (settings.appValue("IntroVideo", "Use_Intro") === "true")
        {
            fadeIn.start();
            videoPlayer.source = "file:/"+_APP_DIR_+"/Media/Frontend/Video/Intro.flv";
        }
        else
        {
            videoPlayer.source = "";
        }
    }

    Keys.onPressed: {
        if (settings.appValue("IntroVideo", "Use_Intro") === "true" &&
                settings.appValue("IntroVideo", "Stop_On_Keypress") === "true")
        {
            videoPlayer.source = "";
        }
    }

    VideoOutput2 {
        id: introOutput
        anchors.fill: parent
        source: videoPlayer
        opengl: true
        fillMode: VideoOutput.PreserveAspectCrop
        orientation: 0
    }
}

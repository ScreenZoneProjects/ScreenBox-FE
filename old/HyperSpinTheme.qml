import QtQuick 2.0
import QtMultimedia 5.4

Rectangle {
    width: parent.width
    height: parent.height

    Image
    {
        id: background

    }

    Image {
        id: artwork1
        //x: 23
        //y: 18
        //width: 100
        //height: 100
        //source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Image {
        id: artwork2
        //x: 23
        //y: 18
        //width: 100
        //height: 100
        //source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Image {
        id: artwork3
        //x: 23
        //y: 18
        //width: 100
        //height: 100
        //source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Image {
        id: artwork4
        //x: 23
        //y: 18
        //width: 100
        //height: 100
        //source: "qrc:/qtquickplugin/images/template_image.png"
    }

    MediaPlayer {
        id: videoPlayer
        //source: "file://video.webm"
        autoPlay: true
    }

    VideoOutput {
        id: videoOutput
        source: videoPlayer
        anchors.fill: parent
    }
}


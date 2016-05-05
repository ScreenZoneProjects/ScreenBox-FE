import QtQuick 2.6
import QtQuick.Controls 1.4
import QtAV 1.6
import QuickFrontend 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    height: settings.appValue("Resolution", "Height");
    minimumHeight: mainWindow.height
    maximumHeight: mainWindow.height
    width: settings.appValue("Resolution", "Width");
    minimumWidth: mainWindow.width
    maximumWidth: mainWindow.width
    title: "ScreenFlow v1.0"
    contentOrientation: Qt.Horizontal
    color: "#000000"

    QuickProcess { id: process }
    QuickSettings { id: settings }

    Component.onCompleted: {
        if (settings.appValue("Startup Program", "Executable") !== "") {
            if (settings.appValue("Startup Program", "WinState") === "MAXIMIZED") {
                mainWindow.visibility = Window.Maximized;
            } else if (settings.appValue("Startup Program", "WinState") === "MINIMIZED") {
                mainWindow.visibility = Window.Minimized;
            }
        } else if (settings.appValue("Resolution", "FullScreen") === "true") {
            mainWindow.visibility = Window.FullScreen;
        }
    }

    onClosing: {
        if (settings.appValue("Exit Program", "Executable") !== "") {
            process.launch(settings.appValue("Exit Program", "Executable"),
                           settings.appValue("Exit Program", "Parameters"),
                           settings.appValue("Exit Program", "Working_Directory"));
            if (settings.appValue("Exit Program", "WinState") === "MAXIMIZED") {
                mainWindow.visibility = Window.Maximized;
            } else if (settings.appValue("Exit Program", "WinState") === "MINIMIZED") {
                mainWindow.visibility = Window.Minimized;
            }
        }
    }

    QuickFrontend {
        id: frontend
        anchors.fill: parent
        currentScene: introScene

        IntroScene {
            id: introScene
            width: parent.width
            height: parent.height
        }

        MenuScene {
            id: menuScene
            width: parent.width
            height: parent.height
        }
    }

    Image {
        id: scanLines
        visible: (settings.appValue("Resolution", "Scanlines_Active") === "true" && settings.appValue("Resolution","Scanlines_Image") !== "")
        source: "file:/"+_APP_DIR_+"/Media/Frontend/Images/Scanlines/"+settings.appValue("Resolution","Scanlines_Image")
        anchors.fill: parent
        opacity: settings.appValue("Resolution","Scanlines_Alpha")
        fillMode: Image.Tile
        horizontalAlignment: Image.AlignLeft
        verticalAlignment: Image.AlignTop
        scale: settings.appValue("Resolution","Scanlines_Scale")
    }

    MediaPlayer {
        id: wheelSoundPlayer
        objectName: "wheelSoundPlayer"
        autoPlay: true
        volume: {
            return settings.appValue("Sound", "Master_Volume") *
                    settings.appValue("Sound", "Wheel_Volume") * 0.0001;
        }
    }

    MediaPlayer {
        id: interfaceSoundPlayer
        objectName: "interfaceSoundPlayer"
        autoPlay: true
        volume: {
            return settings.appValue("Sound", "Interface_Volume") *
                      settings.appValue("Sound", "Master_Volume") * 0.0001;
        }
    }

    MediaPlayer {
        id: videoPlayer
        objectName: "videoPlayer"
        autoPlay: true
        volume: {
            return settings.appValue("Sound", "Master_Volume") *
                    settings.appValue("Sound", "Video_Volume") * 0.0001;
        }
        onStopped: {
            if (frontend.currentScene === introScene) {
                frontend.currentScene = menuScene;
                introScene.destroy();
            }
        }
    }
}
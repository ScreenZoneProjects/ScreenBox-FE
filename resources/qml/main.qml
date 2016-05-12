import QtQuick 2.6
import QtQuick.Controls 1.4
import QtAV 1.6
import QtWebSockets 1.0

// CUSTOM QML
import ScreenBox 1.0
import CoverFlow 1.0
import Scripts 1.0
import Grid 1.0
import Exit 1.0
import Wheel 1.0
import Intro 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    height: settings.appValue("Resolution", "Height");
    minimumHeight: mainWindow.height
    maximumHeight: mainWindow.height
    width: settings.appValue("Resolution", "Width");
    minimumWidth: mainWindow.width
    maximumWidth: mainWindow.width
    title: Qt.application.name + " v" + Qt.application.version
    contentOrientation: Qt.Horizontal
    color: "#000000"


    QuickProcess { id: process }
    QuickSettings { id: settings }

    FontLoader { id: style1Font; source: "qrc:/ttf/ttf/style1.ttf"; }
    FontLoader { id: style2Font; source: "qrc:/ttf/ttf/style2.ttf"; }
    FontLoader { id: style3Font; source: "qrc:/ttf/ttf/style3.ttf"; }
    FontLoader { id: style4Font; source: "qrc:/ttf/ttf/style4.ttf"; }

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

    Timer { id: nfTimer; running: false; interval: 2000; onTriggered: { notFound.visible = false; }}

    QuickFrontend {
        id: frontend
        anchors.fill: parent
        currentDataName: (settings.appValue("Main","Menu_Mode") === "multi") ? "Main Menu" : (settings.appValue("Main","Single_Mode_Name"))
        currentDataType: QuickFrontend.MenuType
        currentScene: introScene
        dataPath: [(settings.appValue("Main", "Menu_Mode") === "multi") ?
                "Main Menu" : settings.appValue("Main", "Last_System")]
        function notFound(fn) {
            notFound.fileName = fn;
            notFound.visible = true;
            nfTimer.start();
        }

        IntroScene {
            id: introScene
            objectName: "introScene"
            anchors.fill: parent
            settings: settings
            videoPlayer: videoPlayer
            enterAnimation: NumberAnimation { target: introScene; property: "opacity"; from: 0; to: 1; duration: 300 }
            exitAnimation: NumberAnimation { target: introScene; property: "opacity"; from: 1; to: 0; duration: 300 }
        }

        WheelScene {
            id: wheelScene
            objectName: "wheelScene"
            anchors.fill: parent
            frontend: frontend
            settings: settings
            exitmenu: exitMenu
            onSwitchScene: {
                frontend.currentScene = gridScene;
            }
            enterAnimation: NumberAnimation { target: wheelScene; property: "opacity"; from: 0; to: 1; duration: 300 }
            exitAnimation: NumberAnimation { target: wheelScene; property: "opacity"; from: 1; to: 0; duration: 300 }
        }

        CoverFlowScene {
            id: coverFlowScene
            objectName: "coverFlowScene"
            anchors.fill: parent
            frontend: frontend
            settings: settings
            onSwitchScene: {
                frontend.currentScene = wheelScene;
            }
            enterAnimation: NumberAnimation { target: coverFlowScene; property: "opacity"; from: 0; to: 1; duration: 300 }
            exitAnimation: NumberAnimation { target: coverFlowScene; property: "opacity"; from: 1; to: 0; duration: 300 }
        }

        GridScene {
            id: gridScene
            objectName: "gridScene"
            frontend: frontend
            settings: settings
            anchors.fill: parent
            onSwitchScene: {
                frontend.currentScene = coverFlowScene;
            }
            enterAnimation: NumberAnimation { target: gridScene; property: "opacity"; from: 0; to: 1; duration: 300 }
            exitAnimation: NumberAnimation { target: gridScene; property: "opacity"; from: 1; to: 0; duration: 300 }
        }
    }

    Rectangle {
        id: notFound
        property string fileName: ""
        visible: false
        anchors.fill: parent
        color: "#CC000000"
        Text {
            id: notFoundText
            text: "Cannot find " + notFound.fileName + ".xml"
            anchors.centerIn: parent
            color: "white"
            scale: 2
        }
    }

    ExitMenu {
        id: exitMenu
        anchors.fill: parent
        opacity: 0
        frontend: frontend
        action: settings.appValue("Main", "Exit_Action")
        pointed: settings.appValue("Main", "Exit_Default")
    }

    Image {
        id: scanLines
        visible: (settings.appValue("Resolution", "Scanlines_Active") === "true" && settings.appValue("Resolution","Scanlines_Image") !== "")
        source: (settings.appValue("Resolution", "Scanlines_Active") === "true" && settings.appValue("Resolution","Scanlines_Image") !== "") ? "file:/"+_APP_DIR_+"/Media/Frontend/Images/Scanlines/"+settings.appValue("Resolution","Scanlines_Image") : ""
        anchors.fill: parent
        opacity: settings.appValue("Resolution","Scanlines_Alpha")
        fillMode: Image.Tile
        horizontalAlignment: Image.AlignLeft
        verticalAlignment: Image.AlignTop
        scale: settings.appValue("Resolution","Scanlines_Scale")
        focus: false
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
                frontend.currentScene = wheelScene;
            }
        }
    }

    WebSocketServer {
        id: server
        port: 3030
        host: "127.0.0.1"
        accept: true

        Component.onCompleted: {
            listen = true
        }

        onListenChanged: {
            console.log("JSON-RPC Server is listening at " + url + "...");
        }

        onClientConnected: {
            webSocket.sendTextMessage(qsTr(JSON.stringify({test: 0})));
            webSocket.onTextMessageReceived.connect(function (msg) {
                var jsonMsg = JSON.parse(msg);
                var response = Utils.handleRequest(jsonMsg);
                webSocket.sendTextMessage(qsTr(response));
            });
        }

        onErrorStringChanged: {
            console.error("[JSON-RPC] Error: " + errorString);
        }
    }
}

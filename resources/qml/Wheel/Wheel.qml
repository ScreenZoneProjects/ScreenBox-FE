import QtQuick 2.5
import QtQuick.XmlListModel 2.0
import QtGraphicalEffects 1.0

import Scripts 1.0
import ScreenBox 1.0

Item {
    /* HyperSpin Official Properties */
    property double alpha: 0.15
    property double color_ratio: 1
    property int horz_large: 400
    property int horz_small: 100
    property int horz_wheel_y: 700
    property int large_text_width: 400
    property int norm_large: 468
    property int norm_small: 230
    property int pin_large: 500
    property int pin_small: 200
    property double shadow_alpha: 1
    property int shadow_angle: 45
    property double shadow_blur: 0
    property color shadow_color: "#000000"
    property int shadow_distance: 6
    property double small_alpha: 1
    property int small_text_width: 260
    property string speed: "high"
    property string style: "normal"
    property color text_color1: "#00BFFD"
    property color text_color2: "#FFFFFF"
    property color text_color3: "#00BFFD"
    property string text_font: "Style4"
    property color text_stroke_color: "#000000"
    property int text_stroke_size: 7
    property int text_width: 700
    property int vert_large: 400
    property int vert_small: 240
    property string vert_wheel_position: "right"

    /* Aliases */
    property alias pathView: wheelPathView
    property alias listModel: database
    property alias delegate: delegate
    property alias alphaTimer: alphaTimer
    property alias offsetTimer: offsetTimer

    /* Other Properties */
    property QuickFrontend f;
    property QuickSettings s;
    property string pointedItem :
        (settings.appValue("Main", "Menu_Mode") === "multi") ?
            "Main Menu" : settings.appValue("Main", "Last_System")
    property string delegateMenuName: f.currentDataName

    /* Signals */
    signal movedUp();
    signal movedDown();
    signal movedSkipUp();
    signal movedSkipDown();
    signal movedSkipUpNumber();
    signal movedSkipDownNumber();
    signal exiting();
    signal selecting();

    opacity: alpha

    anchors.horizontalCenterOffset: {
        if (vert_wheel_position === "left") return -parent.width/4;
        else if (vert_wheel_position === "right") return parent.width/4;
        else return 0;
    }

    function up () {
        alphaFade();
        wheelPathView.decrementCurrentIndex();
        movedUp();
    }

    function down () {
        alphaFade();
        wheelPathView.incrementCurrentIndex();
        movedDown();
    }

    function alphaFade() {
        opacity = 1;
        if (alphaTimer.running)
            alphaTimer.restart();
        else
            alphaTimer.start();
    }

    function skipUp () {
        movedSkipUp();
    }

    function skipDown () {
        movedSkipDown();
    }

    function skipUpNumber () {
        movedSkipUpNumber();
    }

    function skipDownNumber () {
        movedSkipDownNumber();
    }

    function exit () {
        if (f.currentDataName === "Main Menu") {
            if (settings.appValue("Main", "Enable_Exit_Menu") === "true") {
                exitMenu.opacity = 1;
                exitMenu.focus = true;
            } else if (settings.appValue("Main", "Enable_Exit") === "true") {
                Qt.quit();
            }
        } else {
            /* NEED TO HANDLE MULTIWHEEL TO GO BACK */
            pointedItem = "Main Menu"
            select();
        }
        exiting();
    }

    function select () {
        if (f.isValidMenuData(pointedItem)) {
            f.nextDataType = QuickFrontend.MenuType
            enter();
        } else if (f.isValidSystemData(pointedItem)) {
            f.nextDataType = QuickFrontend.SystemType
            enter();
        } else {
            f.notFound(pointedItem);
        }
        selecting();
    }

    function enter () {
        f.nextDataName = pointedItem
        wheelPathView.enabled = false
        if (vert_wheel_position === "left")
            anchors.horizontalCenterOffset = -parent.width;
        else if (vert_wheel_position === "right")
            anchors.horizontalCenterOffset = parent.width;
        else
            anchors.verticalCenterOffset = parent.height;
        offsetTimer.start();
    }

    Behavior on opacity {
        PropertyAnimation { duration: 300 }
    }

    Behavior on anchors.horizontalCenterOffset {
        PropertyAnimation { duration: 300 }
    }

    Timer {
        id: alphaTimer
        running: false
        interval: 1000

        onTriggered: { opacity = alpha; }
    }

    Timer {
        id: offsetTimer
        running: false
        interval: 300
        property bool lastPhase: false

        onTriggered: {
            if (!lastPhase) {
                f.currentDataName = f.nextDataName;
                f.currentDataType = f.nextDataType;
                f.dataPath.push(f.currentDataName)
                f.nextDataType = 0
                f.nextDataName = ""
                start();
                lastPhase = true;
                return;
            }
            if (database.progress === XmlListModel.Loading) {
                start();
                return
            }

            alphaFade();
            if (vert_wheel_position === "left")
                anchors.horizontalCenterOffset = -parent.width/4;
            else if (vert_wheel_position === "right")
                anchors.horizontalCenterOffset = parent.width/4;
            else
                anchors.verticalCenterOffset = 0;
            wheelPathView.enabled = true;
            lastPhase = false;
        }
    }


    XmlListModel {
        id: database
        source: "file://" + _APP_DIR_ + "/Databases/" +
                f.currentDataName + "/" + f.currentDataName + ".xml"
        query: "/menu/game"

        XmlRole { name: "gameName"; query: "@name/string()"; }

        onStatusChanged: {
            if (status === XmlListModel.Ready)
                delegateMenuName = f.currentDataName;
        }
    }

    Component {
        id: delegate
        Item {
            id: wrapper
            visible: PathView.onPath
            rotation: PathView.onPath ? PathView.wheelItemRotation : 0
            width: PathView.isCurrentItem ? norm_large : norm_small
            height: 100
            scale: 0.75            

            Behavior on width { PropertyAnimation { duration: 150 } }


            Text {
                id: wheelItemText
                text: gameName
                visible: false
                font.weight: (text_width === 900) ? Font.Bold : Font.Normal
                font.pixelSize: parent.height
                width: wrapper.PathView.isCurrentItem ?
                           large_text_width : small_text_width
                anchors.horizontalCenter: parent.horizontalCenter
                fontSizeMode: Text.HorizontalFit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                style: Text.Outline
                styleColor: text_stroke_color
                font.family: {
                    if (text_font === "Style4")
                        return style4Font.name;
                    else if (text_font === "Style3")
                        return style3Font.name;
                    else if (text_font === "Style2")
                        return style2Font.name;
                    else
                        return style1Font.name;
                }
                LinearGradient {
                    anchors.fill: wheelItemText
                    source: wheelItemText
                    gradient: Gradient {
                        GradientStop {
                            position: 0;
                            color: text_color1;
                        }
                        GradientStop {
                            position: 0.5*color_ratio;
                            color: text_color2;
                        }
                        GradientStop {
                            position: 1*color_ratio;
                            color: text_color3;
                        }
                    }
                }
            }

            Image {
                id: wheelItemImage
                source: "file://" + _APP_DIR_ + "/Media/" + delegateMenuName +
                        "/Images/Wheel/" + gameName + ".png"
                width: parent.width
                anchors.centerIn: wrapper
                fillMode: Qt.KeepAspectRatio
                visible: true
                onStatusChanged: {
                    if (status === Image.Error)
                    {
                        visible = false;
                        wheelItemText.visible = true;
                    }
                }
            }

            DropShadow {
                anchors.fill: (wheelItemImage.visible) ?
                                  wheelItemImage : wheelItemText
                horizontalOffset: Utils.getHOffset(shadow_angle, shadow_distance)
                verticalOffset: Utils.getVOffset(shadow_angle, shadow_distance)
                radius: shadow_blur
                samples: 8
                opacity: shadow_alpha
                color: shadow_color
                source: (wheelItemImage.visible) ?
                            wheelItemImage : wheelItemText
            }


        }
    }

    Path {
        id: wheelPath
        startX: (vert_wheel_position === "right") ? width : 0
        startY: {
            if (vert_wheel_position === "right") return height;
            else if (vert_wheel_position === "left") return 0;
            else return horz_wheel_y;
        }

        PathAttribute {
            name: "wheelItemRotation";
            value: {
                if (vert_wheel_position === "left") return 0;
                else if (vert_wheel_position === "right") return -90;
                else return 0;
            }
        }

        PathArc {
            x: width*0.5;
            y: (vert_wheel_position === "right" || vert_wheel_position === "left") ? height*0.5 : horz_wheel_y-height/2 ;
            radiusX: width/2;
            radiusY: height/2;
        }
        PathAttribute {
            name: "wheelItemRotation";
            value: {
                if (vert_wheel_position === "left") return 0;
                else if (vert_wheel_position === "right") return 0;
                else return 0;
            }
        }

        PathArc {
            x: (vert_wheel_position === "left") ? 0 : width;
            y: {
                if (vert_wheel_position === "left") return height;
                else if (vert_wheel_position === "right") return 0;
                else return horz_wheel_y;
            }
            radiusX: width*0.5;
            radiusY: height*0.5;
        }

        PathAttribute {
            name: "wheelItemRotation";
            value: {
                if (vert_wheel_position === "left") return 0;
                else if (vert_wheel_position === "right") return 90;
                else return 0;
            }
        }

    }

    PathView {
        id: wheelPathView
        anchors.fill: parent
        model: database
        pathItemCount: 22
        cacheItemCount: 2
        delegate: delegate
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        highlightMoveDuration: (speed === "high") ? 80 : 120
        path: wheelPath

        onCurrentItemChanged: {
            pointedItem = database.get(wheelPathView.currentIndex).gameName;
        }
    }
}

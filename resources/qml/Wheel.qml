import QtQuick 2.5
import QtQuick.XmlListModel 2.0
import QuickFrontend 1.0
import QtGraphicalEffects 1.0

import "Utils.js" as Utils

Rectangle {
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

    property string pointedItem : "MAME"

    property string currentSystem: "Main Menu"

    property alias view: wheelPathView

    property alias timer: wheelTimer

    color: "white"
    opacity: alpha

    Behavior on opacity {
        PropertyAnimation { duration: 300 }
    }

    Timer {
        id: wheelTimer
        running: false
        interval: 1000
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
                font.weight: (text_width === 700) ? Font.Bold : Font.Normal
                font.pixelSize: parent.height
                width: wrapper.PathView.isCurrentItem ? large_text_width : small_text_width
                anchors.horizontalCenter: parent.horizontalCenter
                fontSizeMode: Text.HorizontalFit
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                style: Text.Outline
                styleColor: text_stroke_color

                LinearGradient {
                    anchors.fill: wheelItemText
                    source: wheelItemText
                    gradient: Gradient {
                        GradientStop { position: 0; color: text_color1; }
                        GradientStop { position: 0.5*color_ratio; color: text_color2; }
                        GradientStop { position: 1*color_ratio; color: text_color3; }
                    }
                }
            }

            Image {
                id: wheelItemImage
                source: "file://"+_APP_DIR_+"/Media/"+currentSystem+"/Images/Wheel/"+gameName+".png"
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
                anchors.fill: (wheelItemImage.visible) ? wheelItemImage : wheelItemText
                horizontalOffset: Utils.getHOffset(shadow_angle, shadow_distance)
                verticalOffset: Utils.getVOffset(shadow_angle, shadow_distance)
                radius: shadow_blur
                samples: 8
                opacity: shadow_alpha
                color: shadow_color
                source: (wheelItemImage.visible) ? wheelItemImage : wheelItemText
            }
        }
    }

    PathView {
        id: wheelPathView
        anchors.fill: parent
        model: database
        pathItemCount: 20
        cacheItemCount: 2
        delegate: delegate
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        highlightMoveDuration: 100
        path: Path {
            startX: width
            startY: height
            PathAttribute { name: "wheelItemRotation"; value: -90; }
            PathAttribute { name: "wheelItemWidth"; value: norm_small; }
            PathArc { x: width*0.5; y: height*0.5; radiusX: width/2; radiusY: height/2; } // Middle
            PathAttribute { name: "wheelItemWidth"; value: norm_large; }
            PathAttribute { name: "wheelItemRotation"; value: 0; }
            PathArc { x: width; y: 0; radiusX: width*0.5; radiusY: height*0.5; } // End
            PathAttribute { name: "wheelItemWidth"; value: norm_small; }
            PathAttribute { name: "wheelItemRotation"; value: 90; }
        }
    }
}

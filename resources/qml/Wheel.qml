import QtQuick 2.0
import QtQuick.XmlListModel 2.0
import QuickFrontend 1.0

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

    color: "transparent"
    opacity: 1

    Component {
        id: delegate
        Rectangle {
            color: "red"
            width: 200
            height: 50

            Text {
                anchors.fill: parent
                text: gameName
            }
        }
    }

    PathView {
        anchors.fill: parent
        model: database
        pathItemCount: 12
        delegate: delegate
        path: Path {
            startX: wheel.width
            startY: wheel.height
            PathArc { x: wheel.width; y: 0; radiusX: wheel.width/2; radiusY: wheel.height/2; useLargeArc: false; }
        }
    }

    Component.onCompleted: {

    }
}

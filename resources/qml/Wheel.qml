import QtQuick 2.0

Rectangle {
    color: "transparent"
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
    property color text_color1: "#491490"
    property color text_color2: "#FFF"
    property color text_color3: "#491490"
    property string text_font: "Style4"
    property color text_stroke_color: "#000000"
    property int text_stroke_size: 7
    property int text_width: 700
    property int vert_large: 400
    property int vert_small: 240
    property string vert_wheel_position: "right"

    property string pointedItem : settings.appValue("Main", "Last_System")

    opacity: alpha

    function show (system, cb) {
        return cb()
    }

    function hide (cb) {
        return cb()
    }

    function intialStack(a) {

    }

    function duplicateItems(a, max) {
        var result = new Array(max);
        var i = a.length;
        while (i < max)
        {

            i++;
        }
        return result;
    }

    function loadItemsFromDatabase (database) {     

        var WheelItemComponent = Qt.createComponent("WheelItem.qml");
        var maxItemsNb = 15;
        var items = new Array(maxItemsNb);
        var R = currentWheel.width/2;
        var H = (Math.PI*2)/(maxItemsNb*4);
        var Cx= currentWheel.width/2;
        var Cy = currentWheel.height/2;
        var offset = (Math.PI)*1.27;
        var A = database;
        if (A.length < 15) items = duplicateItems(A, maxItemsNb);
        else if (A.length > 15) items = intialStack(A);
        else items = A;

        for (var i=0; i < maxItemsNb; i++)
        {
            var x= Cx+R*Math.cos(offset-(H*i));
            var y= Cx+R*Math.sin(offset-(H*i));
            var obj = WheelItemComponent.createObject(currentWheel, {
                "x": x, "y": y, "width": norm_small/2, "height": norm_small/4, "baseIndex": i-7, "index": i, "title": items[i]
            });
        }
    }

    Component.onCompleted: loadItemsFromDatabase(["1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"])
}

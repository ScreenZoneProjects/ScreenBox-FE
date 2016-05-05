import QtQuick 2.0

Rectangle {
    color: "white"

    property string pointedItem : settings.appValue("Main", "Last_System")

    function show (system, cb) {
        return cb()
    }

    function hide (cb) {
        return cb()
    }

    function loadItemsFromDatabase (database) {
        var components = new Array(0);
        var wheelItems = new Array(0);
        var ray = currentWheel.width/2;
        var circlePart = (Math.PI*2)/database.length
        for (var i=0; i<database.length; i++)
        {
            // Create buttons instances with a circular shape
            var posX = ray - 10 + ray * Math.cos(circlePart*i+Math.PI);
            var posY = ray - 10 + ray * Math.sin(circlePart*i+Math.PI);
            var component = Qt.createComponent("WheelItem.qml");
            var wheelItem = component.createObject(currentWheel, {
                   "x": posX, "y": posY, "width": 20, "height": 20
             });
            components.push(component);
            wheelItems.push(wheelItem);
        }
    }

    Component.onCompleted: loadItemsFromDatabase(["title1","title2","title3","title4","title5","title2","title3","title4","title5","title2","title3","title4","title5","title2","title3","title4","title5"])
}

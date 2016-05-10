import QtQuick 2.0
import QuickFrontend 1.0
import QtQuick.XmlListModel 2.0
import QtGraphicalEffects 1.0

QuickScene {
    property QuickFrontend frontend
    property QuickSettings settings
    property string currentSystem: "Main Menu"

    signal switchToCoverFlow();
    signal switchToWheel();

    Rectangle {
        id: gridBackground
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0; color: "#2B2A28" }
            GradientStop { position: 1; color: "#171514" }
        }
    }

    XmlListModel {
        id: database
        source: "file://"+_APP_DIR_+"/Databases/"+currentSystem+"/"+currentSystem+".xml"
        query: "/menu/game"

        XmlRole { name: "gameName"; query: "@name/string()"; }
    }

    Component {
        id: delegate
        Item {
            id: wrapper
            width: grid.cellWidth
            height: grid.cellHeight
            Item {
                anchors.fill: parent
                anchors.margins: parent.height/10
                scale: wrapper.GridView.isCurrentItem ? 1.1 : 1

                z: wrapper.GridView.isCurrentItem ? 10 : 1
                Behavior on scale { PropertyAnimation { duration: 100 }}
                Behavior on z { PropertyAnimation { duration: 100 }}
                Image {
                    anchors.fill: parent
                    id: gridItemImage
                    fillMode: Qt.KeepAspectRatioByExpanding
                    source: "file://"+_APP_DIR_+"/Media/"+currentSystem+"/Images/Grids/"+gameName+".png"
                    visible: false
                }
                Rectangle {
                    id: gridItemMask
                    anchors.fill: parent
                    radius: 8
                    visible: false
                }
                OpacityMask {
                    id: gridItemCropped
                    anchors.fill: gridItemImage
                    source: gridItemImage
                    maskSource: gridItemMask
                }

                DropShadow {
                    id: gridItemShadowed
                    anchors.fill: gridItemCropped
                    horizontalOffset: 0
                    verticalOffset: 7
                    radius: 10
                    samples: 8
                    opacity: wrapper.GridView.isCurrentItem ? 1 : .65
                    color: "#000000"
                    source: gridItemCropped

                    Behavior on opacity { PropertyAnimation { duration: 100 } }
                }

            }

        }
    }

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_Up:
            grid.moveCurrentIndexUp();
            break;
        case Qt.Key_Down:
            grid.moveCurrentIndexDown();
            break;
        case Qt.Key_Left:
            grid.moveCurrentIndexLeft();
            break;
        case Qt.Key_Right:
            grid.moveCurrentIndexRight();
            break;
        case Qt.Key_Return:
            break;
        case Qt.Key_Escape:
            break;
        case Qt.Key_W:
            switchToWheel();
            break;
        case Qt.Key_C:
            switchToCoverFlow();
            break;
        default:
            break;
        }
    }

    Component {
        id: highlight

        Rectangle {
            width: grid.cellWidth
            height: grid.cellHeight
            color: "white"
            radius: 8
        }
    }

    Item {
        width: parent.width*.95
        height: parent.height
        anchors.centerIn: parent

        GridView {
            id: grid
            width: parent.width
            height: parent.width/2.29
            anchors.centerIn: parent
            model: database
            // highlight: highlight
            delegate: delegate
            cellHeight: (parent.width/5)/2.3
            cellWidth: parent.width/5
            flow: GridView.LeftToRight
            preferredHighlightBegin: 0.5
            preferredHighlightEnd: 0.5
        }
    }
}

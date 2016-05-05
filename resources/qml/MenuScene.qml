import QtQuick 2.0
import QuickFrontend 1.0

QuickScene {
    property string system: "Main Menu"

    function showAll (nextSystem, cb) {
        currentWheel.show(nextSystem, function () {
            currentTheme.show(nextSystem, function () {
                menuHud.show(function () {
                    cb();
                });
            });
        });
    }

    function hideAll(cb) {
        menuHud.hide(function () {
            currentWheel.hide(function () {
                currentTheme.hide(function () {
                    cb();
                });
            });
        });
    }

    onSystemChanged: {
        menuScene.focus = false
        var nextSystem = menuScene.system
        hideAll(function () {
            showAll (nextSystem, function () {
                menuScene.focus = true
            });
        });
    }

    onRunningChanged: {
        menuScene.focus = false;
        var nextSystem = menuScene.system;
        showAll (nextSystem, function () {
            menuScene.focus = true
        });
    }

    Keys.onPressed: {
        if (exitMenu.visible === false && menuScene.system === "Main Menu" && event.key === Qt.Key_Escape) {
            exitMenu.visible = true;
            return;
        }
        else if (exitMenu.visible === true) {
            switch (event.key) {
                case Qt.Key_Escape:
                    exitMenu.visible = false;
                    break;
                case Qt.Key_Left:
                    exitMenu.pointLeft();
                    break;
                case Qt.Key_Right:
                    exitMenu.pointRight();
                    break;
                default:
                    break;
            }
            return;
        }
        switch (event.key) {
            case Qt.Key_Left:
                break;
            case Qt.Key_Right:
                break;
            case Qt.Key_Up:
                break;
            case Qt.Key_Down:
                break;
            case Qt.Key_Escape:
                menuScene.system = "Main Menu";
                break;
            case Qt.Key_Enter:
                menuScene.system = currentWheel.pointedItem;
                break;
            default:
                break;
        }
    }

    Theme {
        id: currentTheme
        anchors.fill: parent
        color: "blue"
    }
    Hud {
        id: menuHud
        width: parent.width
        height: (parent.height * 0.3)
        anchors.bottom: parent.bottom
    }
    Wheel {
        id: currentWheel
        width: parent.height/2
        height: parent.height/2
        anchors.centerIn: parent
    }

    ExitMenu {
        id: exitMenu
        anchors.fill: parent
        visible: false
    }
}

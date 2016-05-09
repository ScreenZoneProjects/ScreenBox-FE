import QtQuick 2.0
import QuickFrontend 1.0

QuickScene {
    property string system: "Main Menu"
    property bool isValidSystem: frontend.isValidDatabase(system)

    function showAll (nextSystem, cb) {
        if (isValidSystem)
        {
            currentWheel.show(nextSystem, function () {
                currentTheme.show(nextSystem, function () {
                    menuHud.show(function () {
                        cb();
                    });
                });
            });
        }


    }

    function hideAll(cb) {
        if (isValidSystem)
        {
            menuHud.hide(function () {
                currentWheel.hide(function () {
                    currentTheme.hide(function () {
                        cb();
                    });
                });
            });
        }


    }

    onSystemChanged: {
        isValidSystem = frontend.isValidDatabase(system)
        menuScene.focus = false
        var nextSystem = menuScene.system
        hideAll(function () {
            showAll (nextSystem, function () {
                menuScene.focus = true
            });
        });
    }

    /*onRunningChanged: {
        menuScene.focus = false;
        var nextSystem = menuScene.system;
        showAll (nextSystem, function () {
            menuScene.focus = true
        });
    }*/

    Keys.onPressed: {
        if (settings.appValue("Main", "Enable_Exit") === "true" &&
                menuScene.system === "Main Menu" &&
                event.key === Qt.Key_Escape &&
                settings.appValue("Main", "Enable_Exit_Menu") !== "true")
        {
            return Qt.quit();
        }
        else if (exitMenu.visible === false &&
                menuScene.system === "Main Menu" &&
                event.key === Qt.Key_Escape &&
                settings.appValue("Main", "Enable_Exit_Menu") === "true")
        {
            exitMenu.visible = true;
            return;
        }
        else if (exitMenu.visible === true) {
            switch (event.key) {
                case Qt.Key_Escape:
                    exitMenu.visible = false;
                    break;
                case Qt.Key_Left:
                    exitMenu.pointed = "yes";
                    break;
                case Qt.Key_Right:
                    exitMenu.pointed = "no";
                    break;
                case Qt.Key_Return:
                    if (exitMenu.pointed === "yes")
                        return Qt.quit();
                    else
                        exitMenu.visible = false;
                    break;
                default:
                    break;
            }
            return;
        }
        switch (event.key) {
            case Qt.Key_Left:
                currentWheel.goLeft();
                break;
            case Qt.Key_Right:
                currentWheel.goRight();
                break;
            case Qt.Key_Up:
                currentWheel.goUp();
                break;
            case Qt.Key_Down:
                currentWheel.goDown();
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

    Component.onCompleted: {
        var themeComponent = Qt.createComponent("Theme.qml");
        var wheelComponent = Qt.createComponent("Wheel.qml");
        var specialComponent = Qt.createComponent("Special.qml");

        if (isValidSystem) {
            /*
            themeComponent.createObject(menuScene, {
                "id": "currentTheme",
                "anchors.fill": parent,
                "color": "grey"
            });
            specialComponent.createObject(menuScene, {
                "id": "currentSpecial",
                "width": parent.width,
                "height": parent.height*0.3,
                "anchors.bottom": parent.bottom,
                "color": "white"
            });
            wheelComponent.createObject(menuScene, {
                "id": "currentWheel",
                "width": parent.height*2,
                "height": parent.height*2,
                "x": parent.width*2/3,
                "y": -parent.height/2,
                "alpha": settings.mainMenuValue("wheel", "alpha"),
                "color_ratio": settings.mainMenuValue("wheel", "color_ratio"),
                "horz_large": settings.mainMenuValue("wheel", "horz_large"),
                "horz_small": settings.mainMenuValue("wheel", "horz_small"),
                "horz_wheel_y": settings.mainMenuValue("wheel", "horz_wheel_y"),
                "large_text_width": settings.mainMenuValue("wheel", "large_text_width"),
                "norm_large": settings.mainMenuValue("wheel", "norm_large"),
                "norm_small": settings.mainMenuValue("wheel", "norm_small"),
                "pin_large": settings.mainMenuValue("wheel", "pin_large"),
                "pin_small": settings.mainMenuValue("wheel", "pin_small"),
                "shadow_alpha": settings.mainMenuValue("wheel", "shadow_alpha"),
                "shadow_angle": settings.mainMenuValue("wheel", "shadow_angle"),
                "shadow_blur": settings.mainMenuValue("wheel", "shadow_blur"),
                "shadow_color": settings.mainMenuValue("wheel", "shadow_color"),
                "shadow_distance": settings.mainMenuValue("wheel", "shadow_distance"),
                "small_alpha": settings.mainMenuValue("wheel", "small_alpha"),
                "small_text_width": settings.mainMenuValue("wheel", "small_text_width"),
                "speed": settings.mainMenuValue("wheel", "speed"),
                "style": settings.mainMenuValue("wheel", "style"),
                "text_color1": settings.mainMenuValue("wheel", "text_color1"),
                "text_color2": settings.mainMenuValue("wheel", "text_color2"),
                "text_color3": settings.mainMenuValue("wheel", "text_color3"),
                "text_font": settings.mainMenuValue("wheel", "text_font"),
                "text_stroke_color": settings.mainMenuValue("wheel", "text_stroke_color"),
                "text_stroke_size": settings.mainMenuValue("wheel", "text_stroke_size"),
                "text_width": settings.mainMenuValue("wheel", "text_width"),
                "vert_large": settings.mainMenuValue("wheel", "vert_large"),
                "vert_small": settings.mainMenuValue("wheel", "vert_small"),
                "vert_wheel_position": settings.mainMenuValue("wheel", "vert_wheel_position")

            });*/
        } else {
            notFound.visible = true;
        }

    }

    Rectangle {
        id: notFound
        visible: false
        anchors.fill: parent
        color: "#CC000000"
        Text {
            id: notFoundText
            text: "Cannot find " + system + ".xml"
            anchors.centerIn: parent
            color: "white"
            scale: 2
        }
    }

    ExitMenu {
        id: exitMenu
        anchors.fill: parent
        visible: false
        action: settings.appValue("Main", "Exit_Action")
        pointed: settings.appValue("Main", "Exit_Default")
    }
}

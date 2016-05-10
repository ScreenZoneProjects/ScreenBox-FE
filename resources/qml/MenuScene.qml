import QtQuick 2.0
import QuickFrontend 1.0
import QtQuick.XmlListModel 2.0
import "Utils.js" as Colors

QuickScene {
    property string system: "Main Menu"
    property QuickSettings settings
    property QuickFrontend frontend

    function goToSystem (systemName) {
        // Switch to new system here...
        // Call outAnimation for current theme/wheel/specials
        // Change system property to systemName
        // Call inAnimation for new theme/wheel/special
        wheel.visible = true;
        specialArt.visible = true;
        theme.visible = true;
    }

    function previousTitle () {
        wheel.opacity = 1;
        if (wheel.timer.running)
            wheel.timer.restart();
        else
            wheel.timer.start();
        wheel.view.decrementCurrentIndex();
    }

    function nextTitle () {
        wheel.opacity = 1;
        if (wheel.timer.running)
            wheel.timer.restart();
        else
            wheel.timer.start();
        wheel.view.incrementCurrentIndex()
    }

    function previousLetter () {

    }

    function nextLetter () {

    }

    function toggleFavourites () {

    }

    function toggleGenres () {

    }

    XmlListModel {
        id: database
        source: "file://"+_APP_DIR_+"/Databases/"+system+"/"+system+".xml"
        query: "/menu/game"

        XmlRole { name: "gameName"; query: "@name/string()"; }
    }

    Keys.onPressed: {
        if (settings.appValue("Main", "Enable_Exit") === "true" &&
                system === "Main Menu" &&
                event.key === Qt.Key_Escape &&
                settings.appValue("Main", "Enable_Exit_Menu") !== "true")
        {
            return Qt.quit();
        }
        else if (exitMenu.visible === false &&
                system === "Main Menu" &&
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
                previousLetter();
                break;
            case Qt.Key_Right:
                nextLetter();
                break;
            case Qt.Key_Up:
                previousTitle();
                break;
            case Qt.Key_Down:
                nextTitle();
                break;
            case Qt.Key_Escape:
                goToSystem("Main Menu");
                break;
            case Qt.Key_Enter:
                if (system === "Main Menu")
                    goToSystem(wheel.pointedItem);
                else
                    process.rocketLaunch(system, wheel.pointedItem);
                break;
            default:
                break;
        }
    }

    Component.onCompleted: {
        if (frontend.isValidDatabase(system)) {
            goToSystem(system);
        } else {
            notFound.visible = true;
        }
    }

    Theme {
        id: theme
        anchors.fill: parent
        color: "black"
    }

    Special {
        id: specialArt
        anchors.fill: theme
        m_a_active: settings.mainMenuValue("Special Art A", "active")
        m_a_default: settings.mainMenuValue("Special Art A", "default")
        m_a_delay: settings.mainMenuValue("Special Art A", "delay")
        m_a_in: settings.mainMenuValue("Special Art A", "in")
        m_a_length: settings.mainMenuValue("Special Art A", "length")
        m_a_out: settings.mainMenuValue("Special Art A", "out")
        m_a_start: settings.mainMenuValue("Special Art A", "start")
        m_a_type: settings.mainMenuValue("Special Art A", "type")
        m_a_x: settings.mainMenuValue("Special Art A", "x")
        m_a_y: settings.mainMenuValue("Special Art A", "y")

        m_b_active: settings.mainMenuValue("Special Art B", "active")
        m_b_default: settings.mainMenuValue("Special Art B", "default")
        m_b_delay: settings.mainMenuValue("Special Art B", "delay")
        m_b_in: settings.mainMenuValue("Special Art B", "in")
        m_b_length: settings.mainMenuValue("Special Art B", "length")
        m_b_out: settings.mainMenuValue("Special Art B", "out")
        m_b_start: settings.mainMenuValue("Special Art B", "start")
        m_b_type: settings.mainMenuValue("Special Art B", "type")
        m_b_x: settings.mainMenuValue("Special Art B", "x")
        m_b_y: settings.mainMenuValue("Special Art B", "y")

        currentSystem: system
    }

    Wheel {
        id: wheel
        width: parent.height*2
        height: parent.height*2
        anchors.verticalCenter: parent.verticalCenter
        alpha: settings.mainMenuValue("wheel", "alpha")
        color_ratio: settings.mainMenuValue("wheel", "color_ratio")
        horz_large: settings.mainMenuValue("wheel", "horz_large")
        horz_small: settings.mainMenuValue("wheel", "horz_small")
        horz_wheel_y: settings.mainMenuValue("wheel", "horz_wheel_y")
        large_text_width: settings.mainMenuValue("wheel", "large_text_width")
        norm_large: settings.mainMenuValue("wheel", "norm_large")
        norm_small: settings.mainMenuValue("wheel", "norm_small")
        pin_large: settings.mainMenuValue("wheel", "pin_large")
        pin_small: settings.mainMenuValue("wheel", "pin_small")
        shadow_alpha: settings.mainMenuValue("wheel", "shadow_alpha")
        shadow_angle: settings.mainMenuValue("wheel", "shadow_angle")
        shadow_blur: settings.mainMenuValue("wheel", "shadow_blur")
        shadow_color: "#"+Colors.toHex(settings.mainMenuValue("wheel", "shadow_color"))
        shadow_distance: settings.mainMenuValue("wheel", "shadow_distance")
        small_alpha: settings.mainMenuValue("wheel", "small_alpha")
        small_text_width: settings.mainMenuValue("wheel", "small_text_width")
        speed: settings.mainMenuValue("wheel", "speed")
        style: settings.mainMenuValue("wheel", "style")
        text_color1: "#"+Colors.toHex(settings.mainMenuValue("wheel", "text_color1"))
        text_color2: "#"+Colors.toHex(settings.mainMenuValue("wheel", "text_color2"))
        text_color3: "#"+Colors.toHex(settings.mainMenuValue("wheel", "text_color3"))
        text_font: settings.mainMenuValue("wheel", "text_font")
        text_stroke_color: "#"+Colors.toHex(settings.mainMenuValue("wheel", "text_stroke_color"))
        text_stroke_size: settings.mainMenuValue("wheel", "text_stroke_size")
        text_width: settings.mainMenuValue("wheel", "text_width")
        vert_large: settings.mainMenuValue("wheel", "vert_large")
        vert_small: settings.mainMenuValue("wheel", "vert_small")
        vert_wheel_position: settings.mainMenuValue("wheel", "vert_wheel_position")

        currentSystem: system

        timer.onTriggered: { opacity = alpha; }
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

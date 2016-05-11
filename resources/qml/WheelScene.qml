import QtQuick 2.0
import QuickFrontend 1.0
import QtQuick.XmlListModel 2.0
import "Utils.js" as Utils

QuickScene {
    property QuickSettings settings
    property QuickFrontend frontend
    property ExitMenu exitmenu;

    signal switchScene();

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_Up:
            if (!exitmenu.visible)
                wheel.up();
            break;
        case Qt.Key_Down:
            if (!exitmenu.visible)
                wheel.down();
            break;
        case Qt.Key_Left:
            if (!exitmenu.visible)
                wheel.skipDown();
            else
                exitmenu.pointed = "yes"
            break;
        case Qt.Key_Right:
            if (!exitmenu.visible)
                wheel.skipUp();
            else
                exitmenu.pointed = "no"
            break;
        case Qt.Key_Return:
            if (!exitmenu.visible)
                wheel.select();
            else if (exitmenu.pointed === "yes")
                return Qt.quit();
            else
                exitmenu.visible = false;
            break;
        case Qt.Key_Escape:
            if (!exitmenu.visible)
                wheel.exit();
            else
                exitmenu.visible = false;
            break;
        case Qt.Key_S:
            switchScene();
            break;
        default:
            break;
        }
    }

    Component.onCompleted: {
        var validation = frontend.isValidDatabase(frontend.currentDataName);
        if (validation === QuickFrontend.MenuType) {
            /* The database is a Basic Menu */
        } else if (validation === QuickFrontend.SystemType) {
            /* The database is a System Menu */
        }
        else {
            /* The database is invalid */
            frontend.notFound(frontend.currentDataName);
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
    }

    Wheel {
        id: wheel

        anchors.centerIn: parent
        width: parent.height*2
        height: parent.height*2

        f: frontend
        s: settings

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
        shadow_color: "#"+Utils.toHex(settings.mainMenuValue("wheel", "shadow_color"))
        shadow_distance: settings.mainMenuValue("wheel", "shadow_distance")
        small_alpha: settings.mainMenuValue("wheel", "small_alpha")
        small_text_width: settings.mainMenuValue("wheel", "small_text_width")
        speed: settings.mainMenuValue("wheel", "speed")
        style: settings.mainMenuValue("wheel", "style")
        text_color1: "#"+Utils.toHex(settings.mainMenuValue("wheel", "text_color1"))
        text_color2: "#"+Utils.toHex(settings.mainMenuValue("wheel", "text_color2"))
        text_color3: "#"+Utils.toHex(settings.mainMenuValue("wheel", "text_color3"))
        text_font: settings.mainMenuValue("wheel", "text_font")
        text_stroke_color: "#"+Utils.toHex(settings.mainMenuValue("wheel", "text_stroke_color"))
        text_stroke_size: settings.mainMenuValue("wheel", "text_stroke_size")
        text_width: settings.mainMenuValue("wheel", "text_width")
        vert_large: settings.mainMenuValue("wheel", "vert_large")
        vert_small: settings.mainMenuValue("wheel", "vert_small")
        vert_wheel_position: settings.mainMenuValue("wheel", "vert_wheel_position")
    }
}

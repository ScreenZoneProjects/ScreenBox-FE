#include "MenuSettings.h"

#include <QApplication>

MenuSettings::MenuSettings(QString filePath)
{
    path = filePath;
    config = new QSettings(path, QSettings::IniFormat);
    if (!config->contains("wheel/alpha")) {
        generateConfig();
    }
}

void MenuSettings::set(QString group, QString key, QVariant value)
{
    config->setValue(group+"/"+key, value);
}

QVariant MenuSettings::get(QString group, QString key)
{
    return config->value(group+"/"+key, 0);
}

void MenuSettings::generateConfig()
{
    config->beginGroup("wheel");
        config->setValue("alpha", ".15");
        config->setValue("small_alpha", "1");
        config->setValue("style", "normal");
        config->setValue("speed", "high");
        config->setValue("vert_wheel_position", "right");
        config->setValue("norm_large", 468);
        config->setValue("norm_small", 230);
        config->setValue("vert_large", 400);
        config->setValue("vert_small", 240);
        config->setValue("pin_large", 500);
        config->setValue("pin_small", 200);
        config->setValue("horz_large", 400);
        config->setValue("horz_small", 100);
        config->setValue("horz_wheel_y", 700);
        config->setValue("text_width", 700);
        config->setValue("text_font", "Style4");
        config->setValue("small_text_width", 260);
        config->setValue("large_text_width", 400);
        config->setValue("text_stroke_size", 7);
        config->setValue("text_stroke_color", 0x000000);
        config->setValue("text_color1", 0x00BFFD);
        config->setValue("text_color2", 0xFFFFFF);
        config->setValue("text_color3", 0x00BFFD);
        config->setValue("color_ratio", 1);
        config->setValue("shadow_distance", 6);
        config->setValue("shadow_angle", 45);
        config->setValue("shadow_color", 0x000000);
        config->setValue("shadow_alpha", 1);
        config->setValue("shadow_blur", 0);
    config->endGroup();

    config->beginGroup("pointer");
        config->setValue("animated", true);
        config->setValue("x", 965);
        config->setValue("y", 384);
    config->endGroup();

    QString appDir = QApplication::applicationDirPath() + "/Media/Main Menu/Video";

#if __APPLE__
    appDir = appDir.remove("/ScreenFlow.app/Contents/MacOS");
#endif

    config->beginGroup("video defaults");
        config->setValue("path", appDir);
    config->endGroup();

    config->beginGroup("sounds");
        config->setValue("game_sounds", true);
        config->setValue("wheel_click", true);
    config->endGroup();

    config->beginGroup("Special Art A");
        config->setValue("default", true);
        config->setValue("active", true);
        config->setValue("x", 512);
        config->setValue("y", 720);
        config->setValue("in", ".4");
        config->setValue("out", ".4");
        config->setValue("length", 3);
        config->setValue("delay", ".1");
        config->setValue("type", "normal");
        config->setValue("start", "bottom");
    config->endGroup();

    config->beginGroup("Special Art B");
        config->setValue("default", true);
        config->setValue("active", true);
        config->setValue("x", 512);
        config->setValue("y", 740);
        config->setValue("in", ".4");
        config->setValue("out", ".4");
        config->setValue("length", 3);
        config->setValue("delay", ".1");
        config->setValue("type", "fade");
        config->setValue("start", "none");
    config->endGroup();

}

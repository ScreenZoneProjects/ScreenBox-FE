#include "AppSettings.h"

#include <QApplication>
#include <QDir>

AppSettings::AppSettings(QString filePath)
{
    path = filePath;
    config = new QSettings(path, QSettings::IniFormat);
    if (!config->contains("Main/Version")) {
        generateConfig();
    }
}

void AppSettings::set(QString group, QString key, QVariant value)
{
    config->setValue(group+"/"+key, value);
}

QVariant AppSettings::get(QString group, QString key)
{
    return config->value(group+"/"+key, 0);
}

void AppSettings::generateConfig()
{
    config->beginGroup("Main");
        config->setValue("Menu_Mode", "multi");
        config->setValue("Single_Mode_Name", "MAME");
        config->setValue("Enable_Exit_Menu", true);
        config->setValue("Enable_Exit", true);
        config->setValue("Exit_Default", "yes");
        config->setValue("Exit_Action", "exit");
        config->setValue("Version", VERSION_STRING);
        config->setValue("Last_System", "MAME");
        QString platformName = QApplication::platformName();
        if (platformName == "windows")
            config->setValue("HyperLaunch_Path",QDir::toNativeSeparators("C:/Program Files/ScreenZone/ScreenFlow/RLauncher/"));
        else if (platformName == "cocoa")
            config->setValue("HyperLaunch_Path", "/Applications/ScreenZone/RLauncher/");
        else
            config->setValue("HyperLaunch_Path", "/usr/local/ScreenZone/RLauncher/");
    config->endGroup();

    config->beginGroup("Resolution");
        config->setValue("FullScreen", false);
        config->setValue("Width", 800);
        config->setValue("Height", 600);
        config->setValue("Scanlines_Active", false);
        config->setValue("Scanlines_Image", "");
        config->setValue("Scanlines_Scale", 2);
        config->setValue("Scanlines_Alpha", "0.1");
    config->endGroup();

    config->beginGroup("Optimizer");
        config->setValue("CPU_Priority", "normal");
        config->setValue("Quality", "HIGH");
        config->setValue("Image_Smoothing", true);
        config->setValue("Animated_Backgrounds", true);
        config->setValue("Level1_Backgrounds", true);
        config->setValue("Level2_Backgrounds", true);
        config->setValue("Level3_Backgrounds", false);
        config->setValue("Level4_Backgrounds", false);
        config->setValue("Special_Backgrounds", true);
        config->setValue("Wait_For_Special", false);
        config->setValue("Animated_Artworks", true);
        config->setValue("Level1_Artworks", true);
        config->setValue("Level2_Artworks", true);
    config->endGroup();

    config->beginGroup("IntroVideo");
        config->setValue("Use_Intro", true);
        config->setValue("Stop_On_Keypress", true);
    config->endGroup();

    config->beginGroup("Sound");
        config->setValue("Master_Volume", 100);
        config->setValue("Video_Volume", 100);
        config->setValue("Wheel_Volume", 20);
        config->setValue("Interface_Volume", 100);
    config->endGroup();

    config->beginGroup("AttractMode");
        config->setValue("Active", true);
        config->setValue("Time", 60);
        config->setValue("MaxSpineTime", 10);
        config->setValue("HyperSpin", true);
        config->setValue("Wait_For_Video", false);
    config->endGroup();

    config->beginGroup("Keyboard");
        config->setValue("Key_Delay", true);
    config->endGroup();

    config->beginGroup("P1 Controls");
        config->setValue("Start", 13);
        config->setValue("Exit", 27);
        config->setValue("Up", 38);
        config->setValue("Down", 40);
        config->setValue("SkipUp", 37);
        config->setValue("SkipDown", 39);
        config->setValue("SkipUpNumber", 70);
        config->setValue("SkipDownNumber", 86);
        config->setValue("HyperSpin", 32);
        config->setValue("Genre", 71);
        config->setValue("Favorites", 76);
    config->endGroup();

    config->beginGroup("P2 Controls");
        config->setValue("Start", 69);
        config->setValue("Exit", 81);
        config->setValue("Up", 87);
        config->setValue("Down", 83);
        config->setValue("SkipUp", 65);
        config->setValue("SkipDown", 68);
        config->setValue("SkipUpNumber", 74);
        config->setValue("SkipDownNumber", 77);
        config->setValue("HyperSpin", 88);
        config->setValue("Genre", 72);
        config->setValue("Favorites", 90);
    config->endGroup();

    config->beginGroup("P1 Joystick");
        config->setValue("Enabled", false);
        config->setValue("Joy", 0);
        config->setValue("Threshold", 40);
        config->setValue("Start", "Button_1");
        config->setValue("Exit", "Button_2");
        config->setValue("Up", "Analog_Up");
        config->setValue("Down", "Analog_Down");
        config->setValue("SkipUp", "Analog_Left");
        config->setValue("SkipDown", "Analog_Right");
        config->setValue("SkipUpNumber", "Button_3");
        config->setValue("SkipDownNumber", "Button_4");
        config->setValue("HyperSpin", "Button_5");
        config->setValue("Genre", "Button_6");
        config->setValue("Favorites", "Button_7");
    config->endGroup();

    config->beginGroup("P2 Joystick");
        config->setValue("Enabled", false);
        config->setValue("Joy", 1);
        config->setValue("Threshold", 40);
        config->setValue("Start", "Button_1");
        config->setValue("Exit", "Button_2");
        config->setValue("Up", "Analog_Up");
        config->setValue("Down", "Analog_Down");
        config->setValue("SkipUp", "Analog_Left");
        config->setValue("SkipDown", "Analog_Right");
        config->setValue("SkipUpNumber", "Button_3");
        config->setValue("SkipDownNumber", "Button_4");
        config->setValue("HyperSpin", "Button_5");
        config->setValue("Genre", "Button_6");
        config->setValue("Favorites", "Button_7");
    config->endGroup();

    config->beginGroup("Trackball");
        config->setValue("Enabled", false);
        config->setValue("Sensitivity", 90);
    config->endGroup();

    config->beginGroup("Spinner");
        config->setValue("Enabled", false);
        config->setValue("Sensitivity", 90);
    config->endGroup();

    config->beginGroup("Startup Program");
        config->setValue("Executable", "");
        config->setValue("Parameters", "");
        config->setValue("Working_Directory", "");
        config->setValue("WinState", "");
    config->endGroup();

    config->beginGroup("Exit Program");
        config->setValue("Executable", "");
        config->setValue("Parameters", "");
        config->setValue("Working_Directory", "");
        config->setValue("WinState", "NORMAL");
    config->endGroup();

    config->beginGroup("LEDBlinky");
        config->setValue("Active", false);
        config->setValue("Path", "");
    config->endGroup();

    config->beginGroup("HiScore");
        config->setValue("Active", false);
        config->setValue("Y", 550);
        config->setValue("Delay", 2);
    config->endGroup();
}

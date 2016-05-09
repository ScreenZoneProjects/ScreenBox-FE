/*
*      Copyright (C) 2015 Team ScreenZone
*      http://screenzone.fr
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#include "Settings.hpp"
#include "../utils/IniParser.hpp"

Settings::Settings()
{
    workingDir = "Settings/";
    QString settingsFilePath = workingDir+QString("Settings.ini");
    QString menuFilePath = workingDir+QString("Main Menu.ini");
    IniParser fParser, mParser;
    if (fParser.read(settingsFilePath) != IniParser::NONE)
    {
        initFrontendSettings();
        fParser.write(settingsFilePath, m_frontendSettings);
    }

    if (mParser.read(menuFilePath) != IniParser::NONE)
    {
        initMenuSettings();
        mParser.write(menuFilePath, m_mainMenuSettings);
    }
    m_frontendSettings = fParser.getMap();
    m_mainMenuSettings = mParser.getMap();
}


Settings::~Settings()
{
    m_frontendSettings.clear();
    m_mainMenuSettings.clear();
}

QString Settings::Frontend(QString section, QString key)
{
    return m_frontendSettings[section][key];
}

QString Settings::MainMenu(QString section, QString key)
{
    return m_mainMenuSettings[section][key];
}

QString Settings::System(QString systemName, QString section, QString key)
{
    std::map<QString, std::map<QString, QString> > map = m_systemSettings(systemName);
    return map[section][key];
}

void Settings::initMenuSettings()
{
    m_ms_wheel["alpha"]                          = ".15";
    m_ms_wheel["small"]                          = "1";
    m_ms_wheel["style"]                          = "normal";
    m_ms_wheel["speed"]                          = "high";
    m_ms_wheel["vert_wheel_position"]            = "right";
    m_ms_wheel["norm_large"]                     = "468";
    m_ms_wheel["norm_small"]                     = "230";
    m_ms_wheel["vert_large"]                     = "400";
    m_ms_wheel["vert_small"]                     = "240";
    m_ms_wheel["pin_large"]                      = "500";
    m_ms_wheel["pin_small"]                      = "200";
    m_ms_wheel["horz_large"]                     = "400";
    m_ms_wheel["horz_small"]                     = "100";
    m_ms_wheel["horz_wheel_y"]                   = "700";
    m_ms_wheel["text_width"]                     = "700";
    m_ms_wheel["text_font"]                      = "Style4";
    m_ms_wheel["small_text_width"]               = "260";
    m_ms_wheel["large_text_width"]               = "400";
    m_ms_wheel["text_stroke_size"]               = "7";
    m_ms_wheel["text_stroke_color"]              = "0x000000";
    m_ms_wheel["text_color1"]                    = "0x00BFFD";
    m_ms_wheel["text_color2"]                    = "0xFFFFFF";
    m_ms_wheel["text_color3"]                    = "0x00BFFD";
    m_ms_wheel["color_ratio"]                    = "1";
    m_ms_wheel["shadow_distance"]                = "6";
    m_ms_wheel["shadow_angle"]                   = "45";
    m_ms_wheel["shadow_color"]                   = "0x000000";
    m_ms_wheel["shadow_alpha"]                   = "1";
    m_ms_wheel["shadow_blur"]                    = "0";

    m_ms_pointer["animated"]                     = "true";
    m_ms_pointer["x"]                            = "965";
    m_ms_pointer["y"]                            = "384";

    m_ms_videodefaults["path"]                   = "Media/Main Menu/Video";

    m_ms_sounds["game_sounds"]                   = "true";
    m_ms_sounds["wheel_click"]                   = "true";

    m_ms_spearta["default"]                      = "true";
    m_ms_spearta["active"]                       = "true";
    m_ms_spearta["x"]                            = "512";
    m_ms_spearta["y"]                            = "720";
    m_ms_spearta["in"]                           = ".4";
    m_ms_spearta["out"]                          = ".4";
    m_ms_spearta["length"]                       = "3";
    m_ms_spearta["delay"]                        = ".1";
    m_ms_spearta["type"]                         = "normal";
    m_ms_spearta["start"]                        = "bottom";

    m_ms_speartb["default"]                      = "true";
    m_ms_speartb["active"]                       = "true";
    m_ms_speartb["x"]                            = "512";
    m_ms_speartb["y"]                            = "720";
    m_ms_speartb["in"]                           = ".4";
    m_ms_speartb["out"]                          = ".4";
    m_ms_speartb["length"]                       = "3";
    m_ms_speartb["delay"]                        = ".1";
    m_ms_speartb["type"]                         = "fade";
    m_ms_speartb["start"]                        = "none";



    m_mainMenuSettings["wheel"]                  = m_ms_wheel;
    m_mainMenuSettings["pointer"]                = m_ms_pointer;
    m_mainMenuSettings["video defaults"]         = m_ms_videodefaults;
    m_mainMenuSettings["sounds"]                 = m_ms_sounds;
    m_mainMenuSettings["Special Art A"]          = m_ms_spearta;
    m_mainMenuSettings["Special Art B"]          = m_ms_speartb;
}

void Settings::initFrontendSettings()
{

    // Frontend settings initialization

    m_fs_main["Menu_Mode"]                   = "multi";
    m_fs_main["Single_Mode_Name"]            = "MAME";
    m_fs_main["Enable_Exit_Menu"]            = "true";
    m_fs_main["Enable_Exit"]                 = "true";
    m_fs_main["Exit_Default"]                = "yes";
    m_fs_main["Exit_Action"]                 = "exit";
    m_fs_main["Version"]                     = "1.0.0.0";
    m_fs_main["Last_System"]                 = "MAME";
    m_fs_main["Hyperlaunch_Path"]            = "C:\\Hyperspin\\HyperLaunch\\";


    m_fs_resolution["FullScreen"]            = "false";
    m_fs_resolution["Width"]                 = "800";
    m_fs_resolution["Height"]                = "600";
    m_fs_resolution["Scanlines_Active"]      = "false";
    m_fs_resolution["Scanlines_Image"]       = "";
    m_fs_resolution["Scanlines_Scale"]       = "2";
    m_fs_resolution["Scanlines_Alpha"]       = "0.1";


    m_fs_optimizer["CPU_Priority"]           = "normal";
    m_fs_optimizer["Quality"]                = "HIGH";
    m_fs_optimizer["Image_Smoothing"]        = "true";
    m_fs_optimizer["Animated_Backgrounds"]   = "true";
    m_fs_optimizer["Inter_Backgrounds"]      = "false";
    m_fs_optimizer["Level1_backgrounds"]     = "true";
    m_fs_optimizer["Level2_backgrounds"]     = "true";
    m_fs_optimizer["Level3_backgrounds"]     = "false";
    m_fs_optimizer["Level4_backgrounds"]     = "false";
    m_fs_optimizer["Special_Backgrounds"]    = "normal";
    m_fs_optimizer["Wait_For_Special"]       = "false";
    m_fs_optimizer["Animated_Artworks"]      = "true";
    m_fs_optimizer["Level1_Artworks"]        = "true";
    m_fs_optimizer["Level1_Artworks"]        = "true";


    m_fs_introvideo["Use_Intro"]             = "false";
    m_fs_introvideo["Stop_On_Keypress"]      = "true";


    m_fs_sound["Master_Volume"]              = "100";
    m_fs_sound["Video_Volume"]               = "100";
    m_fs_sound["Wheel_Volume"]               = "20";
    m_fs_sound["Interface_Volume"]           = "100";


    m_fs_attractMode["Active"]               = "true";
    m_fs_attractMode["Time"]                 = "60";
    m_fs_attractMode["MaxSpineTime"]         = "10";
    m_fs_attractMode["HyperSpin"]            = "true";
    m_fs_attractMode["Wait_For_Video"]       = "false";


    m_fs_keyboard["Key_Delay"]               = "true";


    m_fs_p1controls["Start"]                 = "13";
    m_fs_p1controls["Exit"]                  = "27";
    m_fs_p1controls["Up"]                    = "38";
    m_fs_p1controls["Down"]                  = "40";
    m_fs_p1controls["SkipUp"]                = "37";
    m_fs_p1controls["SkipDown"]              = "39";
    m_fs_p1controls["SkipUpNumber"]          = "70";
    m_fs_p1controls["SkipDownNumber"]        = "86";
    m_fs_p1controls["HyperSpin"]             = "32";
    m_fs_p1controls["Genre"]                 = "71";
    m_fs_p1controls["Favorites"]             = "76";


    m_fs_p2controls["Start"]                 = "69";
    m_fs_p2controls["Exit"]                  = "81";
    m_fs_p2controls["Up"]                    = "87";
    m_fs_p2controls["Down"]                  = "83";
    m_fs_p2controls["SkipUp"]                = "65";
    m_fs_p2controls["SkipDown"]              = "68";
    m_fs_p2controls["SkipUpNumber"]          = "74";
    m_fs_p2controls["SkipDownNumber"]        = "77";
    m_fs_p2controls["HyperSpin"]             = "88";
    m_fs_p2controls["Genre"]                 = "72";
    m_fs_p2controls["Favorites"]             = "90";


    m_fs_p1joystick["Enabled"]               = "false";
    m_fs_p1joystick["Joy"]                   = "0";
    m_fs_p1joystick["Threshold"]             = "40";
    m_fs_p1joystick["Start"]                 = "Button_1";
    m_fs_p1joystick["Exit"]                  = "Button_2";
    m_fs_p1joystick["Up"]                    = "Analog_Up";
    m_fs_p1joystick["Down"]                  = "Analog_Down";
    m_fs_p1joystick["SkipUp"]                = "Analog_Left";
    m_fs_p1joystick["SkipDown"]              = "Analog_Right";
    m_fs_p1joystick["SkipUpNumber"]          = "Button_3";
    m_fs_p1joystick["SkipDownNumber"]        = "Button_4";
    m_fs_p1joystick["HyperSpin"]             = "Button_5";
    m_fs_p1joystick["Genre"]                 = "Button_6";
    m_fs_p1joystick["Favorites"]             = "Button_7";


    m_fs_p2joystick["Enabled"]               = "false";
    m_fs_p2joystick["Joy"]                   = "1";
    m_fs_p2joystick["Threshold"]             = "40";
    m_fs_p2joystick["Start"]                 = "Button_1";
    m_fs_p2joystick["Exit"]                  = "Button_2";
    m_fs_p2joystick["Up"]                    = "Analog_Up";
    m_fs_p2joystick["Down"]                  = "Analog_Down";
    m_fs_p2joystick["SkipUp"]                = "Analog_Left";
    m_fs_p2joystick["SkipDown"]              = "Analog_Right";
    m_fs_p2joystick["SkipUpNumber"]          = "Button_3";
    m_fs_p2joystick["SkipDownNumber"]        = "Button_4";
    m_fs_p2joystick["HyperSpin"]             = "Button_5";
    m_fs_p2joystick["Genre"]                 = "Button_6";
    m_fs_p2joystick["Favorites"]             = "Button_7";


    m_fs_trackball["Enabled"]                = "false";
    m_fs_trackball["Sensitivity"]            = "90";


    m_fs_spinner["Enabled"]                  = "false";
    m_fs_spinner["Sensitivity"]              = "90";


    m_fs_startupprogram["Executable"]        = "";
    m_fs_startupprogram["Parameters"]        = "";
    m_fs_startupprogram["Working_Directory"] = "";
    m_fs_startupprogram["WinState"]          = "";


    m_fs_exitprogram["Executable"]           = "";
    m_fs_exitprogram["Parameters"]           = "";
    m_fs_exitprogram["Working_Directory"]    = "";
    m_fs_exitprogram["WinState"]             = "NORMAL";


    m_fs_led["Active"]                       = "false";
    m_fs_led["Path"]                         = "";


    m_fs_hiscore["Active"]                   = "false";
    m_fs_hiscore["Y"]                        = "550";
    m_fs_hiscore["Delay"]                    = "2";


    m_frontendSettings["Main"]               = m_fs_main;
    m_frontendSettings["Resolution"]         = m_fs_resolution;
    m_frontendSettings["Optimizer"]          = m_fs_optimizer;
    m_frontendSettings["IntroVideo"]         = m_fs_introvideo;
    m_frontendSettings["Sound"]              = m_fs_sound;
    m_frontendSettings["AttractMode"]        = m_fs_attractMode;
    m_frontendSettings["Keyboard"]           = m_fs_keyboard;
    m_frontendSettings["P1 Controls"]        = m_fs_p1controls;
    m_frontendSettings["P2 Controls"]        = m_fs_p2controls;
    m_frontendSettings["P1 Joystick"]        = m_fs_p1joystick;
    m_frontendSettings["P2 Joystick"]        = m_fs_p2joystick;
    m_frontendSettings["Trackball"]          = m_fs_trackball;
    m_frontendSettings["Spinner"]            = m_fs_spinner;
    m_frontendSettings["Startup Program"]    = m_fs_startupprogram;
    m_frontendSettings["Exit Program"]       = m_fs_exitprogram;
    m_frontendSettings["LEDBlinky"]          = m_fs_led;
    m_frontendSettings["HiScore"]            = m_fs_hiscore;

}


bool Settings::fileExists(QString fileName)
{
    IniParser testParser;
    if (testParser.read(workingDir+fileName+".ini") != IniParser::NONE) {
        return false;
    }
    return true;
}


std::map<QString, std::map<QString, QString> > Settings::m_systemSettings(QString systemName)
{
    IniParser sParser;
    m_currentSystem = systemName;
    sParser.read(workingDir+systemName+".ini");
    return sParser.getMap();
}

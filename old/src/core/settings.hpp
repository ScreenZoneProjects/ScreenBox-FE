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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <QString>

class Settings
{
public:
    bool fileExists(QString fileName);

    Settings();
    ~Settings();

    QString Frontend(QString section, QString key);
    QString MainMenu(QString section, QString key);
    QString System(QString systemName, QString section, QString key);

private:
    QString workingDir;

    std::map<QString, std::map<QString, QString> > m_frontendSettings;
    std::map<QString, std::map<QString, QString> > m_mainMenuSettings;
    std::map<QString, std::map<QString, QString> > m_systemSettings(QString systemName);

    QString m_currentSystem;

    std::map<QString, QString> m_fs_main;
    std::map<QString, QString> m_fs_resolution;
    std::map<QString, QString> m_fs_optimizer;
    std::map<QString, QString> m_fs_introvideo;
    std::map<QString, QString> m_fs_sound;
    std::map<QString, QString> m_fs_attractMode;
    std::map<QString, QString> m_fs_keyboard;
    std::map<QString, QString> m_fs_p1controls;
    std::map<QString, QString> m_fs_p2controls;
    std::map<QString, QString> m_fs_p1joystick;
    std::map<QString, QString> m_fs_p2joystick;
    std::map<QString, QString> m_fs_trackball;
    std::map<QString, QString> m_fs_spinner;
    std::map<QString, QString> m_fs_startupprogram;
    std::map<QString, QString> m_fs_exitprogram;
    std::map<QString, QString> m_fs_led;
    std::map<QString, QString> m_fs_hiscore;


    std::map<QString, QString> m_ms_wheel;
    std::map<QString, QString> m_ms_pointer;
    std::map<QString, QString> m_ms_videodefaults;
    std::map<QString, QString> m_ms_sounds;
    std::map<QString, QString> m_ms_spearta;
    std::map<QString, QString> m_ms_speartb;


    std::map<QString, QString> m_ss_exeinfo;
    std::map<QString, QString> m_ss_filters;
    std::map<QString, QString> m_ss_themes;
    std::map<QString, QString> m_ss_wheel;
    std::map<QString, QString> m_ss_pointer;
    std::map<QString, QString> m_ss_videodefaults;
    std::map<QString, QString> m_ss_sounds;
    std::map<QString, QString> m_ss_navigation;
    std::map<QString, QString> m_ss_spearta;
    std::map<QString, QString> m_ss_speartb;
    std::map<QString, QString> m_ss_speartc;
    std::map<QString, QString> m_ss_gametext;


    void initFrontendSettings();
    void initMenuSettings();
};

#endif // SETTINGS_H

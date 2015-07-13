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

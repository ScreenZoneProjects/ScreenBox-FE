#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QList>

#include "AppSettings.h"
#include "MenuSettings.h"
#include "SystemSettings.h"

class Settings
{
public:
    Settings(QString directoryPath);
    ~Settings();
    AppSettings * app();
    MenuSettings * mainMenu();
    void addSystem(SystemSettings * systemSettings);
    static bool isLegacySystemSettingsFile(QString settingsFilePath);
private:
    AppSettings * m_appSettings;
    MenuSettings * m_menuSettings;
    QList<SystemSettings*> m_systemSettingsList;
};

#endif // SETTINGS_H

#include "Settings.h"

#include <QFileInfo>
#include <QFile>

Settings::Settings(QString directoryPath)
{
    QString appSettingsPath = directoryPath + QString("/Settings.ini");
    m_appSettings = new AppSettings(appSettingsPath);

    QString menuSettingsPath = directoryPath + QString("/Main Menu.ini");
    m_menuSettings = new MenuSettings(menuSettingsPath);
}

Settings::~Settings()
{

}

AppSettings * Settings::app()
{
    return m_appSettings;
}

MenuSettings * Settings::mainMenu()
{
    return m_menuSettings;
}

void Settings::addSystem(SystemSettings * systemSettings)
{
    m_systemSettingsList.append(systemSettings);
}

bool Settings::isLegacySystemSettingsFile(QString settingsFilePath)
{
    QFileInfo settingsFile (settingsFilePath);
    if (!settingsFile.exists() || !settingsFile.isFile())
        return false;
    return SystemSettings::checkFile(settingsFile);
}

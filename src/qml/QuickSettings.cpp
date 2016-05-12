#include "QuickSettings.h"
#include <QApplication>

QuickSettings::QuickSettings(QObject * parent) : QObject(parent)
{
    QString settingsPath = QApplication::applicationDirPath() + SETDIR_PATH;

    if (QApplication::platformName() == "cocoa")
        settingsPath = settingsPath.remove(OSX_DIR_SUFFIX);

    m_settings = new Settings(settingsPath);
}
QVariant QuickSettings::appValue(QString group, QString key)
{
    return m_settings->app()->get(group, key);
}

QVariant QuickSettings::mainMenuValue(QString group, QString key)
{
    return m_settings->mainMenu()->get(group, key);
}

QVariant QuickSettings::systemMenuValue(QString , QString )
{
    return 0;
}

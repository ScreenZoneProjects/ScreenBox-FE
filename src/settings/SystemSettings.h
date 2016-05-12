#ifndef SYSTEMSETTINGS_H
#define SYSTEMSETTINGS_H

#include <QFileInfo>

class SystemSettings
{
public:
    SystemSettings();
    static bool checkFile(QFileInfo settingsFile);
};

#endif // SYSTEMSETTINGS_H

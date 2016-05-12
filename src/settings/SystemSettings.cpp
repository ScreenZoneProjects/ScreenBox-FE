#include "SystemSettings.h"

#include <QFile>

SystemSettings::SystemSettings()
{

}

bool SystemSettings::checkFile(QFileInfo settingsFile)
{
    QFile file (settingsFile.absoluteFilePath());

    // Check file here...

    return false;
}

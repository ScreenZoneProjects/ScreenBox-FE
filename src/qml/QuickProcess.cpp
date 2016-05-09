#include "QuickProcess.h"

#include <QProcess>

QuickProcess::QuickProcess(QObject * parent) : QObject(parent)
{

}

void QuickProcess::launch(QString command, QString args, QString workingDir)
{
    QString finalCommand ("cd "+workingDir+" && "+command+" "+args);
    QProcess::startDetached(finalCommand);
}

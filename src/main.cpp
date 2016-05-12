#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QThread>
#include <QProcess>
#include <QMessageBox>
#include <QCursor>

#include "utils/AppIntegrity.h"
#include "settings/Settings.h"
#include "qml/QuickScene.h"
#include "qml/QuickSettings.h"
#include "qml/QuickProcess.h"
#include "qml/QuickFrontend.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setApplicationVersion(VERSION_STRING);
    application.setApplicationName(APPLICATION_NAME_STRING);
    QString appTitle = QString(APPLICATION_NAME_STRING) + QString(" v.") + QString(VERSION_STRING);
    application.setApplicationDisplayName(appTitle);
    application.setOrganizationName(ORGANIZATION_NAME_STRING);
    application.setOrganizationDomain(ORGANIZATION_DOMAIN_STRING);



    QString applicationDirPath = application.applicationDirPath();

    if (application.platformName() == "cocoa")
        applicationDirPath = applicationDirPath.remove(OSX_DIR_SUFFIX);

    QString settingsPath = applicationDirPath + SETDIR_PATH;

    Settings * settings  = new Settings(settingsPath);

    AppIntegrity appIntegrity (settings);

    if (appIntegrity.getStatus() == AppIntegrity::ERROR)
    {
        QMessageBox alert(QMessageBox::Icon::Critical,
                          "Error",
                          "Error(s) found in your application directories !");
        alert.setInformativeText("Error code : ");
        alert.setDetailedText(appIntegrity.getDetails());
        alert.exec();
        return -1;
    }

    QString cpuPriority = settings->app()->get("Optimizer", "CPU_Priority").toString();

    if (cpuPriority == "highest")
        application.thread()->setPriority(QThread::HighestPriority);
    else if (cpuPriority == "high")
        application.thread()->setPriority(QThread::HighPriority);
    else if (cpuPriority == "low")
        application.thread()->setPriority(QThread::LowPriority);
    else if (cpuPriority == "lowest")
        application.thread()->setPriority(QThread::LowestPriority);
    else
        application.thread()->setPriority(QThread::NormalPriority);

    if (settings->app()->get("Startup Program", "Executable").toString() != "")
    {
        QProcess::startDetached("cd " +
           settings->app()->get("Startup Program","Working_Directory").toString()+
           " && " +
           settings->app()->get("Startup Program", "Executable").toString() + " "+
           settings->app()->get("Startup Program", "Parameters").toString());

    }

    delete settings;

    application.setOverrideCursor(QCursor(Qt::BlankCursor));

    qmlRegisterType<QuickSettings>(APPLICATION_NAME_STRING, 1, 0, "QuickSettings");
    qmlRegisterType<QuickProcess>(APPLICATION_NAME_STRING, 1, 0, "QuickProcess");
    qmlRegisterType<QuickScene>(APPLICATION_NAME_STRING, 1, 0, "QuickScene");
    qmlRegisterType<QuickFrontend>(APPLICATION_NAME_STRING, 1, 0, "QuickFrontend");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_APP_DIR_", applicationDirPath);
    engine.load(QUrl(QStringLiteral("qrc:/qml/qml/main.qml")));

    QObject::connect(&engine, SIGNAL(quit()), &application, SLOT(quit()));
    return application.exec();
}

#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QVariant>
#include <QSettings>
#include <QTextStream>

class QString;
class QSettings;
class QVariant;

class AppSettings
{

public:
    AppSettings(QString filePath);
    void set(QString group, QString key, QVariant value);
    QVariant get(QString group, QString key);

private:
    void generateConfig();
    QSettings * config;
    QString path;
};

#endif // APPSETTINGS_H

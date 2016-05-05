#ifndef MENUSETTINGS_H
#define MENUSETTINGS_H


#include <QString>
#include <QVariant>
#include <QSettings>
#include <QTextStream>

class QString;
class QSettings;
class QVariant;

class MenuSettings
{

public:
    MenuSettings(QString filePath);
    void set(QString group, QString key, QVariant value);
    QVariant get(QString group, QString key);

private:
    void generateConfig();
    QSettings * config;
    QString path;
};

#endif // MENUSETTINGS_H

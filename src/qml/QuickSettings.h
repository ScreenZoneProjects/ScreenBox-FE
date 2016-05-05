#ifndef QUICKSETTINGS_H
#define QUICKSETTINGS_H


#include <QObject>
#include "../settings/Settings.h"

class QuickSettings : public QObject
{
    Q_OBJECT
public:
    QuickSettings(QObject * parent = 0);
    Q_INVOKABLE QVariant appValue(QString group, QString key);
    Q_INVOKABLE QVariant mainMenuValue(QString group, QString key);
    Q_INVOKABLE QVariant systemMenuValue(QString , QString );
private:
    Settings * m_settings;
};

#endif // QUICKSETTINGS_H

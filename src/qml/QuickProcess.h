#ifndef QUICKPROCESS_H
#define QUICKPROCESS_H

#include <QObject>

class QuickProcess : public QObject
{
    Q_OBJECT

public:
    explicit QuickProcess(QObject *parent = 0);
    Q_INVOKABLE void launch(QString command, QString args, QString workingDir);
};

#endif // QUICKPROCESS_H

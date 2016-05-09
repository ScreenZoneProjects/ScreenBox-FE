#pragma once

#include <QObject>
#include <QString>
#include <QLocale>

class CFranchise : public QObject
{
	Q_OBJECT

public:
	explicit CFranchise(QObject *parent = 0);

private:
	QString m_sName;
	QMap<QLocale::Language, QString> m_vsDescriptions;

signals:

public slots:
};


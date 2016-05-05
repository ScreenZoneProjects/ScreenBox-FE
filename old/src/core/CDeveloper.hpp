#pragma once

#include <QObject>
#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QLocale>

#include "CIndexable.hpp"
#include "CDescription.hpp"

class CDeveloper : public QObject, public CIndexable
{
	Q_OBJECT

	//Q_PROPERTY(QString description READ getDescription)
	Q_PROPERTY(QString name READ getName)
	Q_PROPERTY(QString id READ getId)

public:
	explicit CDeveloper(QObject *parent = 0);
	CDeveloper(qint64 i64Id, QString sName, QString sDescription);

	QString getName() const;
	void setName(const QString &sName);

	QString getDescription() const;
	QString getDescription(QLocale::Language eLanguage) const;
	void setDescription(QLocale::Language eLanguage, QString sDescription);

private:
	QString m_sName; //< The name of the developer studio/team.
	CDescription m_oDescriptions; //< A description of the developer studio/team.

signals:

public slots:
};

#pragma once

#include <QMap>
#include <QString>
#include <QLocale>

#include "CIndexable.hpp"

class CDescription: public CIndexable
{
public:
	CDescription();
	CDescription(qint64 i64Id);

	QString getDescription() const;
	QString getDescription(QLocale::Language eLanguage) const;
	void setDescription(QLocale::Language eLanguage, QString sDescription);

private:
	QMap<QLocale::Language, QString> m_mDescriptions;

signals:

public slots:
};

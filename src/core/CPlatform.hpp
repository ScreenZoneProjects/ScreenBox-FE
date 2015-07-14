#pragma once

#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QLocale>

#include "CManufacturer.hpp"

class CPlatform
{
public:
	CPlatform();

	quint32 getId() const;
	void setId(const quint32 &ui32Id);

	QString getName() const;
	void setName(const QString &sName);

	QString getDescription() const;
	void setDescription(const QString &sDescription);

private:
	quint32 m_ui32Id; //< Unique ID.
	QString m_sName; //
	QMap<QLocale::Language, QString> m_vsDescriptions; // Description of the platform.
	CManufacturer* m_pManufacturer;
};

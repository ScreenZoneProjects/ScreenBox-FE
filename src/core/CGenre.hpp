#pragma once

#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QLocale>

class CGenre
{
public:
	CGenre();

	quint32 getId() const;
	void setId(const quint32& ui32Id);

	QString getName() const;
	void setName(const QString& sName);

	QMap<QLocale::Language, QString> getDescriptions() const;
	void setDescriptions(const QMap<QLocale::Language, QString>& getDescriptions);

private:
	quint32 m_ui32Id; // Unique ID.
	QString m_sName;
	QMap<QLocale::Language, QString> m_vsDescriptions;
};


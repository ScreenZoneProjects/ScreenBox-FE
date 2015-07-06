#pragma once

#include <QtGlobal>
#include <QString>

class CGenre
{
public:
	CGenre();

	quint32 getId() const;
	void setId(const quint32 &ui32Id);

	QString getName() const;
	void setName(const QString &sName);

	QString getDescription() const;
	void setDescription(const QString &sDescription);

private:
	quint32 m_ui32Id;
	QString m_sName;
	QString m_sDescription;
};

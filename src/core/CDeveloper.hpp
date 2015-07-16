#pragma once

#include <QtGlobal>
#include <QString>

class CDeveloper
{
public:
	CDeveloper();
	CDeveloper(quint32 ui32Id, QString sName, QString sDescription);

	quint32 getId() const;
	void setId(const quint32 &ui32Id);

	QString getName() const;
	void setName(const QString &sName);

	QString getDescription() const;
	void setDescription(const QString &sDescription);

private:
	quint32 m_ui32Id;
	QString m_sName; //< The name of the developer studio/team.
	QString m_sDescription; //< A description of the developer studio/team.

};

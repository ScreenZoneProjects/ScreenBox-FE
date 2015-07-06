#include "CDeveloper.hpp"

CDeveloper::CDeveloper()
{

}

QString CDeveloper::getDescription() const
{
	return m_sDescription;
}

void CDeveloper::setDescription(const QString &sDescription)
{
	m_sDescription = sDescription;
}

quint32 CDeveloper::getId() const
{
	return m_ui32Id;
}

void CDeveloper::setId(const quint32 &ui32Id)
{
	m_ui32Id = ui32Id;
}

QString CDeveloper::getName() const
{
	return m_sName;
}

void CDeveloper::setName(const QString &sName)
{
	m_sName = sName;
}



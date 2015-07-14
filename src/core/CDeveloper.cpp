#include "CDeveloper.hpp"

CDeveloper::CDeveloper()
{

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




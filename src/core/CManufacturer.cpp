#include "CManufacturer.hpp"

CManufacturer::CManufacturer()
{

}
quint32 CManufacturer::getId() const
{
	return m_ui32Id;
}

void CManufacturer::setId(const quint32& ui32Id)
{
	m_ui32Id = ui32Id;
}
QString CManufacturer::getName() const
{
	return m_sName;
}

void CManufacturer::setName(const QString& sName)
{
	m_sName = sName;
}
QString CManufacturer::getDescription() const
{
	return m_sDescription;
}

void CManufacturer::setDescription(const QString& sDescription)
{
	m_sDescription = sDescription;
}





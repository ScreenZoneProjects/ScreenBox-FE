#include "CManufacturer.hpp"

CManufacturer::CManufacturer(QObject *parent) : QObject(parent)
{

}

QString CManufacturer::getName() const
{
	return m_sName;
}

void CManufacturer::setName(const QString& sName)
{
	m_sName = sName;
	this->setObjectName(m_sName + " manufacturer object");
}

CDescription& CManufacturer::getDescriptionReference()
{
	return m_oDescription;
}

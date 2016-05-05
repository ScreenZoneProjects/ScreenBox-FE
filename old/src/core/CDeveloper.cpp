#include "CDeveloper.hpp"

CDeveloper::CDeveloper(QObject *parent) : QObject(parent)
{

}

QString CDeveloper::getName() const
{
	return m_sName;
}

void CDeveloper::setName(const QString &sName)
{
	m_sName = sName;
}


#include "CGenre.hpp"

CGenre::CGenre(QObject *parent) : QObject(parent)
{

}

QString CGenre::getName() const
{
	return m_sName;
}

void CGenre::setName(const QString& sName)
{
	m_sName = sName;
}

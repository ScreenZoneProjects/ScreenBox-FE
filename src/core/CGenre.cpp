#include "CGenre.hpp"

CGenre::CGenre()
{

}
quint32 CGenre::getId() const
{
	return m_ui32Id;
}

void CGenre::setId(const quint32& ui32Id)
{
	m_ui32Id = ui32Id;
}
QString CGenre::getName() const
{
	return m_sName;
}

void CGenre::setName(const QString& sName)
{
	m_sName = sName;
}
QMap<QLocale::Language, QString> CGenre::getDescriptions() const
{
	return m_vsDescriptions;
}

void CGenre::setDescriptions(const QMap<QLocale::Language, QString>& vsDescriptions)
{
	m_vsDescriptions = vsDescriptions;
}


#include "CDescription.hpp"

CDescription::CDescription()
{
}

CDescription::CDescription(qint64 i64Id)
{
	this->setId(i64Id);
}

QString CDescription::getDescription() const
{
	return this->getDescription(QLocale().language());
}

QString CDescription::getDescription(QLocale::Language eLanguage) const
{
	if(m_mDescriptions.contains(eLanguage))
	{
		return m_mDescriptions[eLanguage];
	}
	else if(m_mDescriptions.contains(QLocale::Language::English))
	{
		return m_mDescriptions[QLocale::Language::English];
	}

	return "No description available.";
}

void CDescription::setDescription(QLocale::Language eLanguage, QString sDescription)
{
	if(m_mDescriptions.contains(eLanguage))
	{
		m_mDescriptions[eLanguage] = sDescription;
	}
	else
	{
		m_mDescriptions.insert(eLanguage, sDescription);
	}
}

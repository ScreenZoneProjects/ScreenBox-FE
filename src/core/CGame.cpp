#include "CGame.hpp"

CGame::CGame()
{

}
QMap<QLocale::Language, QString> CGame::getNames() const
{
	return m_vsNames;
}

void CGame::setNames(const QMap<QLocale::Language, QString>& vsNames)
{
	m_vsNames = vsNames;
}

quint64 CGame::getId() const
{
    return m_ui64Id;
}

void CGame::setId(const quint64& ui64Id)
{
    m_ui64Id = ui64Id;
}

QMap<QLocale::Language, QString> CGame::getSynopsis() const
{
	return m_vsSynopsis;
}

void CGame::setSynopsis(const QMap<QLocale::Language, QString>& vsSynopsis)
{
	m_vsSynopsis = vsSynopsis;
}
quint8 CGame::getPlayerCount() const
{
	return m_ui8PlayerCount;
}

void CGame::setPlayerCount(const quint8& ui8PlayerCount)
{
	m_ui8PlayerCount = ui8PlayerCount;
}





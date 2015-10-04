#include "CGame.hpp"

CGame::CGame(QObject *parent) : QObject(parent)
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

quint8 CGame::getPlayerCount() const
{
	return m_ui8PlayerCount;
}

void CGame::setPlayerCount(const quint8& ui8PlayerCount)
{
	m_ui8PlayerCount = ui8PlayerCount;
}

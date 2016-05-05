#pragma once

#include <QObject>
#include <QPointer>

#include "CRom.hpp"
#include "CGame.hpp"
#include "CDeveloper.hpp"

class CPlatformGame : public QObject
{
	Q_OBJECT
public:
	explicit CPlatformGame(QObject *parent = 0);

private:
	QList<CRom> m_voRom;
	QPointer<CGame> m_pGame;

	QList< QPointer<CDeveloper> > m_vpDevelopers;

signals:

public slots:
};

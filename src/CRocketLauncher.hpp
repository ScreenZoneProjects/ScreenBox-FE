#pragma once

#include <QFileInfo>
#include <QProcess>
#include <QCoreApplication>

#include "CRom.hpp"

class CRocketLauncher
{
public:
	CRocketLauncher();

	launchGame(const CRom& oRom);

private:
	QFileInfo m_oExecutable;
	bool m_bIsAvailable;
};

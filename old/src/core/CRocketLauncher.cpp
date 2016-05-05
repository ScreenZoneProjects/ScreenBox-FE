#include "CRocketLauncher.hpp"

CRocketLauncher::CRocketLauncher()
{

}

bool CRocketLauncher::launchGame(const CRom& oRom)
{
	QStringList parameters; parameters << "-r \"" << oRom.getFileInfo().absoluteFilePath() << "\""
									   //<< "-s \"" + oRom.m_pPlatform->getName()<< "\""
									   << "-f \"" << QCoreApplication::applicationFilePath() << "\""
									   << "-p \"" << "ScreenZone" << "\"";
	QProcess *l_pProcess = new QProcess();
	l_pProcess->startDetached(m_oExecutable.absoluteFilePath(), parameters);

	return true;
}


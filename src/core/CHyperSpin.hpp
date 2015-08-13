#pragma once

#include <QString>
#include <QDir>
#include <QFileInfoList>

#include "CHyperSpinTheme.hpp"

class CHyperSpin
{
public:
	CHyperSpin();

	bool scanThemes();

private:
	QDir m_oMediaDirectoryPath;

	CHyperSpinTheme m_oMainMenuHyperSpinTheme;
};

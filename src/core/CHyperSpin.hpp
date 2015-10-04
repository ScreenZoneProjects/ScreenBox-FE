#pragma once

#include <QString>
#include <QDir>
#include <QFileInfoList>

#include "CHyperSpinTheme.hpp"
#include "CPlatform.hpp"

class CHyperSpin
{
public:
	CHyperSpin();

	bool scanMedias();
	bool scanPlatformMedias(QFileInfo oPlatformDirectory);
	bool scanImages(QFileInfo oPlatformImagesDirectory);
	bool scanSounds(QFileInfo oPlatformSoundsDirectory);
	bool scanThemes(QFileInfo oPlatformThemesDirectory);
	bool scanVideos(QFileInfo oPlatformVideosDirectory);

private:
	QDir m_oMediaDirectoryPath;

	CHyperSpinTheme m_oMainMenuHyperSpinTheme;
};

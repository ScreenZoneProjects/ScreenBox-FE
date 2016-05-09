#include "CHyperSpin.hpp"

CHyperSpin::CHyperSpin()
{

}

bool CHyperSpin::scanMedias()
{
	QFileInfoList l_voSystemDirectories = m_oMediaDirectoryPath.entryInfoList();

	QList<CPlatform> l_voPlatforms;

	if(QFileInfo::exists(m_oMediaDirectoryPath.absolutePath() + "Main Menu"))
	{

	}

	foreach(const QFileInfo &oSystemDirectory, l_voSystemDirectories)
	{
		if(oSystemDirectory.isDir())
		{
		}
		else
		{
		}
	}

	return true;
}

bool CHyperSpin::scanPlatformMedias(QFileInfo oPlatformDirectory)
{
	bool l_bIsImagesDirectoryFound = false;
	bool l_bIsSoundDirectoryFound = false;
	bool l_bIsThemesDirectoryFound = false;
	bool l_bIsVideoDirectoryFound = false;

	bool l_bIsMainMenuDirectory = (oPlatformDirectory.baseName() == "Main Menu");
	bool l_bIsFrontendDirectory = (oPlatformDirectory.baseName() == "Frontend");

	if(!l_bIsMainMenuDirectory && !l_bIsFrontendDirectory)
	{
		CPlatform l_oPlatform;
		l_oPlatform.setName(oPlatformDirectory.baseName());

		foreach(const QFileInfo &oMediaDirectory, oPlatformDirectory.absoluteDir().entryInfoList())
		{
			CHyperSpinTheme l_oHyperSpinTheme;

			if(oMediaDirectory.baseName() == "Images")
			{
				l_bIsImagesDirectoryFound = true;

				if(!scanImages(oMediaDirectory))
				{

				}
			}
			else if(oMediaDirectory.baseName() == "Sound")
			{
				l_bIsSoundDirectoryFound = true;

				if(!scanSounds(oMediaDirectory))
				{

				}
			}
			else if(oMediaDirectory.baseName() == "Themes")
			{
				l_bIsThemesDirectoryFound = true;

				if(!scanThemes(oMediaDirectory))
				{

				}
			}
			else if(oMediaDirectory.baseName() == "Video")
			{
				l_bIsVideoDirectoryFound = true;

				if(!scanVideos(oMediaDirectory))
				{

				}
			}
			else
			{

			}
		}
	}

	return true;
}

bool CHyperSpin::scanImages(QFileInfo oPlatformImagesDirectory)
{
	foreach(const QFileInfo &oImageMediaDirectory, oPlatformImagesDirectory.absoluteDir().entryInfoList())
	{
		if(oImageMediaDirectory.baseName() == "Artwork1")
		{

		}
		else if(oImageMediaDirectory.baseName() == "Artwork2")
		{

		}
		else if(oImageMediaDirectory.baseName() == "Artwork3") // Jaquettes
		{

		}
		else if(oImageMediaDirectory.baseName() == "Artwork4") // Cartbridges
		{

		}
		else if(oImageMediaDirectory.baseName() == "Backgrounds")
		{

		}
		else if(oImageMediaDirectory.baseName() == "Genre")
		{
			foreach(const QFileInfo &oImageGenreMediaDirectory, oImageMediaDirectory.absoluteDir().entryInfoList())
			{
				if(oImageGenreMediaDirectory.baseName() == "Backgrounds")
				{

				}
				else if(oImageGenreMediaDirectory.baseName() == "Wheel")
				{

				}
			}
		}
		else if(oImageMediaDirectory.baseName() == "Letters")
		{

		}
		else if(oImageMediaDirectory.baseName() == "Other")
		{
			foreach(const QFileInfo &oImagePointerMediaDirectory, oImageMediaDirectory.absoluteDir().entryInfoList())
			{
				if(oImagePointerMediaDirectory.isFile())
				{
					if(oImagePointerMediaDirectory.baseName() == "Pointer")
					{

					}
					else
					{

					}
				}
			}
		}
		else if(oImageMediaDirectory.baseName() == "Particle")
		{

		}
		else if(oImageMediaDirectory.baseName() == "Special")
		{

		}
		else if(oImageMediaDirectory.baseName() == "Wheel")
		{
			foreach(const QFileInfo &oImageWheelMediaDirectory, oImageMediaDirectory.absoluteDir().entryInfoList())
			{
				if(oImageWheelMediaDirectory.isFile())
				{

				}
			}
		}
		else
		{

		}
	}

	return true;
}

bool CHyperSpin::scanSounds(QFileInfo oPlatformSoundsDirectory)
{
	foreach(const QFileInfo &oSoundMediaDirectory, oPlatformSoundsDirectory.absoluteDir().entryInfoList())
	{
		if(oSoundMediaDirectory.isDir())
		{
			if(oSoundMediaDirectory.baseName() == "Background Music")
			{

			}
			else if(oSoundMediaDirectory.baseName() == "System Exit")
			{

			}
			else if(oSoundMediaDirectory.baseName() == "System Start")
			{

			}
			else if(oSoundMediaDirectory.baseName() == "Wheel Sounds")
			{
				QFileInfoList l_voWheelSoundFiles;

				foreach(const QFileInfo &oWheelSoundMediaFile, oSoundMediaDirectory.absoluteDir().entryInfoList())
				{
					if(oWheelSoundMediaFile.isFile())
					{
						l_voWheelSoundFiles.append(oWheelSoundMediaFile);
					}
				}
			}
		}
		else if (oSoundMediaDirectory.isFile())
		{
			if(oSoundMediaDirectory.baseName() == "Wheel Click")
			{

			}
		}
	}

	return true;
}

bool CHyperSpin::scanThemes(QFileInfo oPlatformThemesDirectory)
{
	foreach(const QFileInfo &oThemeMediaFile, oPlatformThemesDirectory.absoluteDir().entryInfoList())
	{
		if(oThemeMediaFile.isFile())
		{
			if(oThemeMediaFile.completeSuffix() == "zip" || oThemeMediaFile.completeSuffix() == "rar" || oThemeMediaFile.completeSuffix() == "7z")
			{

			}
			else
			{

			}
		}
	}

	return true;
}

bool CHyperSpin::scanVideos(QFileInfo oPlatformVideosDirectory)
{
	foreach(const QFileInfo &oVideoMediaFile, oPlatformVideosDirectory.absoluteDir().entryInfoList())
	{
		if(oVideoMediaFile.completeSuffix() == "mp4" || oVideoMediaFile.completeSuffix() == "flv" || oVideoMediaFile.completeSuffix() == "avi" || oVideoMediaFile.completeSuffix() == "flv")
		{

		}
	}

	return true;
}

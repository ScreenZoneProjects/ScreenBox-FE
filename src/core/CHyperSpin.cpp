#include "CHyperSpin.hpp"

CHyperSpin::CHyperSpin()
{

}

bool CHyperSpin::scanThemes()
{
	QFileInfoList l_voSystemDirectories = m_oMediaDirectoryPath.entryInfoList();

	foreach(const QFileInfo &oSystemDirectory, l_voSystemDirectories)
	{
		if(oSystemDirectory.isDir())
		{
			QString l_sSystemDirectoryName = oSystemDirectory.baseName();

			bool l_bIsImagesDirectoryFound = false;
			bool l_bIsSoundDirectoryFound = false;
			bool l_bIsThemesDirectoryFound = false;
			bool l_bIsVideoDirectoryFound = false;

			bool l_bIsMainMenuDirectory = (l_sSystemDirectoryName == "Main Menu");
			bool l_bIsFrontendDirectory = (l_sSystemDirectoryName == "Frontend");



			foreach(const QFileInfo &oMediaDirectory, oSystemDirectory.absoluteDir().entryInfoList())
			{
				CHyperSpinTheme l_oHyperSpinTheme;

				if(oMediaDirectory.baseName() == "Images")
				{
					l_bIsImagesDirectoryFound = true;

					foreach(const QFileInfo &oImageMediaDirectory, oMediaDirectory.absoluteDir().entryInfoList())
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
				}
				else if(oMediaDirectory.baseName() == "Sound")
				{
					l_bIsSoundDirectoryFound = true;

					foreach(const QFileInfo &oSoundMediaDirectory, oMediaDirectory.absoluteDir().entryInfoList())
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
				}
				else if(oMediaDirectory.baseName() == "Themes")
				{
					l_bIsThemesDirectoryFound = true;

					foreach(const QFileInfo &oThemeMediaFile, oMediaDirectory.absoluteDir().entryInfoList())
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

				}
				else if(oMediaDirectory.baseName() == "Video")
				{
					l_bIsVideoDirectoryFound = true;

					foreach(const QFileInfo &oVideoMediaFile, oMediaDirectory.absoluteDir().entryInfoList())
					{
						if(oVideoMediaFile.completeSuffix() == "mp4" || oVideoMediaFile.completeSuffix() == "flv" || oVideoMediaFile.completeSuffix() == "avi" || oVideoMediaFile.completeSuffix() == "flv")
						{

						}
					}
				}
				else
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



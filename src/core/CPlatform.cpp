#include "CPlatform.hpp"
#include "CCommonTool.hpp"

#include <QDir>


CPlatform::CPlatform(QObject *parent) : QObject(parent)
{

}

QString CPlatform::getName() const
{
	return m_sName;
}

void CPlatform::setName(const QString &sName)
{
	m_sName = sName;
}

bool CPlatform::scanMedia()
{
	foreach(const QFileInfo &oMediaFile, m_oMediaFilePath.absoluteDir().entryInfoList())
	{
		if(oMediaFile.isDir())
		{
			QString l_sMediaFileBaseName = oMediaFile.baseName();

			if(l_sMediaFileBaseName == "3D Models")
			{
				foreach(const QFileInfo &o3DModelsFiles, m_oMediaFilePath.absoluteDir().entryInfoList())
				{
					if(o3DModelsFiles.isDir())
					{
						if(o3DModelsFiles.baseName() == "Cartbrigdes")
						{

						}
						else if(o3DModelsFiles.baseName() == "Platform")
						{

						}
					}
				}
			}
			else if(l_sMediaFileBaseName == "Fonts")
			{
				foreach(const QFileInfo &oFontsFiles, m_oMediaFilePath.absoluteDir().entryInfoList())
				{
					if(oFontsFiles.isDir())
					{

					}
					else if(oFontsFiles.isFile())
					{
						m_oFontFile = oFontsFiles;
						break;
					}
				}
			}
			else if(l_sMediaFileBaseName == "Images")
			{
				foreach(const QFileInfo &oImagesFiles, m_oMediaFilePath.absoluteDir().entryInfoList())
				{
					if(oImagesFiles.isDir())
					{
						QString l_sImageFileBaseName = oImagesFiles.baseName();

						if(l_sImageFileBaseName == "Artworks")
						{
							foreach(const QFileInfo &oArtworksFiles, oImagesFiles.absoluteDir().entryInfoList())
							{
								if(oArtworksFiles.isDir())
								{

								}
								else if(oArtworksFiles.isFile())
								{
									m_voArtworksFiles.push_back(oArtworksFiles);
								}
							}
						}
						else if(l_sImageFileBaseName == "Fanarts")
						{
							foreach(const QFileInfo &oFanartFile, oImagesFiles.absoluteDir().entryInfoList())
							{
								if(oFanartFile.isDir())
								{

								}
								else if(oFanartFile.isFile())
								{
									m_voFanartsFiles.push_back(oFanartFile);
								}
							}
						}
						else if(l_sImageFileBaseName == "Pictures")
						{
							foreach(const QFileInfo &oPictureFile, oImagesFiles.absoluteDir().entryInfoList())
							{
								if(oPictureFile.isDir())
								{

								}
								else if(oPictureFile.isFile())
								{
									QString l_oFileSuffix = oPictureFile.suffix();

									if(l_oFileSuffix == "png" || l_oFileSuffix == "jpg" )
									{
										m_voPicturesFiles.push_back(oPictureFile);
									}
								}
							}
						}
						else if(l_sImageFileBaseName == "Logo")
						{
							foreach(const QFileInfo &oLogoFile, oImagesFiles.absoluteDir().entryInfoList())
							{
								if(oLogoFile.isDir())
								{

								}
								else if(oLogoFile.isFile())// && CCommonTool::checkImageCompatibility(oLogoFile))
								{
									QString l_oFileBaseName = oLogoFile.baseName();

									if(l_oFileBaseName == "color")
									{
										m_oLogoColorImageFilePath = oLogoFile;
									}
									else if(l_oFileBaseName == "monochrome")
									{
										m_oLogoMonochromeImageFilePath = oLogoFile;
									}
								}
							}
						}
					}
				}
			}
			else if(l_sMediaFileBaseName == "Manuals")
			{
				foreach(const QFileInfo &oManualFile, m_oMediaFilePath.absoluteDir().entryInfoList())
				{
					if(oManualFile.isDir())
					{

					}
					else if(oManualFile.isFile())
					{
						QString l_oFileSuffix = oManualFile.suffix();

						if(l_oFileSuffix == "pdf")
						{
							m_voManualsFiles.push_back(oManualFile);
						}
					}
				}
			}
			else if(l_sMediaFileBaseName == "Marquees")
			{
				foreach(const QFileInfo &oMarqueesFile, m_oMediaFilePath.absoluteDir().entryInfoList())
				{
					if(oMarqueesFile.isDir())
					{

					}
					else if(oMarqueesFile.isFile())
					{
						m_oMarqueeFiles.push_back(oMarqueesFile);
					}
				}
			}
			else if(l_sMediaFileBaseName == "Videos")
			{
				this->scanVideos(m_oMediaFilePath.absoluteDir().entryInfoList());
			}
		}
	}

	return true;
}

bool CPlatform::scanVideos(QFileInfoList oFileInfoList)
{
	foreach(const QFileInfo &oVideosFiles, oFileInfoList)
	{
		if(oVideosFiles.isDir())
		{
			this->scanVideos(oVideosFiles.absoluteDir().entryInfoList());
		}
		else if(oVideosFiles.isFile())
		{
			if(CCommonTool::checkVideoCompatibility(oVideosFiles))
			{
				m_voVideosFiles.push_back(oVideosFiles);
			}
		}
	}

	return true;
}

QString CPlatform::getCoverSupport3DModelPath() const
{
	return m_sCoverSupport3DModelPath;
}

void CPlatform::setCoverSupport3DModelPath(const QString &sCoverSupport3DModelPath)
{
	m_sCoverSupport3DModelPath = sCoverSupport3DModelPath;
}

QFont CPlatform::getFont() const
{
	return m_oFont;
}

void CPlatform::setFont(const QFont &oFont)
{
	m_oFont = oFont;
}

QList<QFileInfo> CPlatform::getPicturesFiles() const
{
	return m_voPicturesFiles;
}

void CPlatform::setPicturesFiles(const QList<QFileInfo> &voPicturesFiles)
{
	m_voPicturesFiles = voPicturesFiles;
}

QFileInfo CPlatform::getLogoMonochromeImageFilePath() const
{
	return m_oLogoMonochromeImageFilePath;
}

void CPlatform::setLogoMonochromeImageFilePath(const QFileInfo &oLogoMonochromeImageFilePath)
{
	m_oLogoMonochromeImageFilePath = oLogoMonochromeImageFilePath;
}

QFileInfo CPlatform::getLogoColorImageFilePath() const
{
	return m_oLogoColorImageFilePath;
}

void CPlatform::setLogoColorImageFilePath(const QFileInfo &oLogoColorImageFilePath)
{
	m_oLogoColorImageFilePath = oLogoColorImageFilePath;
}

CDescription& CPlatform::getDescriptionReference()
{
	return m_oDescription;
}

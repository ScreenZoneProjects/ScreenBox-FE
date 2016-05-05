#pragma once

#include <QObject>
#include <QtGlobal>
#include <QString>
#include <QMap>
#include <QLocale>
#include <QFileInfo>
#include <QPixmap>
#include <QFont>

#include "CPlatformGame.hpp"
#include "CDescription.hpp"
#include "CIndexable.hpp"

class CPlatform : public QObject, public CIndexable
{
	Q_OBJECT

	//Q_PROPERTY(QString id READ getId)
	Q_PROPERTY(QFont font READ getFont)
	Q_PROPERTY(QFileInfo logoColor READ getLogoColorImageFilePath)
	Q_PROPERTY(QFileInfo logoMonochrome READ getLogoMonochromeImageFilePath)
	Q_PROPERTY(QFileInfoList pictures READ getPicturesFiles)

public:
	explicit CPlatform(QObject *parent = 0);

	QString getName() const;
	void setName(const QString &sName);

	CDescription& getDescriptionReference();

	bool scanMedia();
	
	QFileInfo getLogoColorImageFilePath() const;
	void setLogoColorImageFilePath(const QFileInfo &oLogoColorImageFilePath);

	QFileInfo getLogoMonochromeImageFilePath() const;
	void setLogoMonochromeImageFilePath(const QFileInfo &oLogoMonochromeImageFilePath);

	QList<QFileInfo> getPicturesFiles() const;
	void setPicturesFiles(const QList<QFileInfo> &voPicturesFiles);

	QFont getFont() const;
	void setFont(const QFont &oFont);

	QString getCoverSupport3DModelPath() const;
	void setCoverSupport3DModelPath(const QString &sCoverSupport3DModelPath);

	bool scanVideos(QFileInfoList oFileInfoList);

private:
	QString m_sName; //< Main name of the platform.
	CDescription m_oDescription; // Description of the platform.

	QFileInfo m_oMediaFilePath;

	// Logos
	QFileInfo m_oLogoColorImageFilePath;
	QFileInfo m_oLogoMonochromeImageFilePath;

	// Pictures
	QFileInfoList m_voPicturesFiles;

	// Manuals
	QFileInfoList m_voManualsFiles;

	// Artworks
	QFileInfoList m_voArtworksFiles;
	QList<QPixmap> m_voArtworksImage;

	// Fanarts
	QFileInfoList m_voFanartsFiles;
	QList<QPixmap> m_voFanartsImage;

	// Videos
	QFileInfoList m_voVideosFiles;

	QMap<qint64,CPlatformGame> m_vPlatformGames;

	QPixmap m_o2DCartbridge;

	QString m_sCoverSupport3DModelPath;

	// Font
	QFileInfo m_oFontFile;
	QFont m_oFont; // Font usually used in the commercial products of this platform.

	// Marquees
	QFileInfoList m_oMarqueeFiles;
	QFileInfoList m_oBetaBriteFiles;

signals:

public slots:
};

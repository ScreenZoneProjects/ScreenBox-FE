#pragma once

#include <QXmlStreamReader>
#include <QFile>

#include "CHyperSpinThemeMedia.hpp"
#include "CHyperSpinThemeArtwork.hpp"
#include "CHyperSpinThemeParticle.hpp"
#include "CHyperSpinThemeVideo.hpp"

class CHyperSpinTheme
{
public:
	CHyperSpinTheme();
	bool parseATheme();

private:
	QVector<CHyperSpinThemeMedia> m_voHyperSpinMedias;

	template<typename T>
	bool parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(T)> convertFunction);

	//template<>
	//bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(float)> convertFunction);

	/*bool parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(float)> convertFunction);
	bool parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(int)> convertFunction);
	bool parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(CHyperSpinThemeMedia::EStartingPosition)> convertFunction);
	bool parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(CHyperSpinThemeMedia::EAnimationType)> convertFunction);
	bool parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(CHyperSpinThemeMedia::ERestingAnimation)> convertFunction);
	*/

	QString m_sFilePath;

	CHyperSpinThemeVideo m_oHyperSpinVideo;
	QVector<CHyperSpinThemeArtwork> m_voHyperSpinArtworks;

};


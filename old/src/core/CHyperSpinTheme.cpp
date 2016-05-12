#include <QtDebug>
#include <functional>

#include "CHyperSpinTheme.hpp"

CHyperSpinTheme::CHyperSpinTheme()
{

}

template<typename T>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(T)> convertFunction)
{
	qWarning() << "Type not available";
	return false;
}

template<>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(float)> convertFunction)
{
	if(oXMLStreamReader.attributes().hasAttribute(sAttributeName))
	{
		bool l_bConvertSuccess = false;
		float l_value = oXMLStreamReader.attributes().value(sAttributeName).toFloat(&l_bConvertSuccess);

		if(l_bConvertSuccess)
		{
			convertFunction(l_value);
		}
		else
		{
			qWarning() << "Failed to convert the [" << sAttributeName << "] attribute of the theme "<< m_sFilePath;
		}

		return true;
	}

	return false;
}

template<>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(bool)> convertFunction)
{
	if(oXMLStreamReader.attributes().hasAttribute(sAttributeName))
	{
		QStringRef l_value = oXMLStreamReader.attributes().value(sAttributeName);

		if(l_value == "true")
		{
			convertFunction(true);
		}
		else if(l_value == "false")
		{
			convertFunction(false);
		}
		else
		{
			qWarning() << "Failed to convert the [" << sAttributeName << "] attribute of the theme "<< m_sFilePath;
			return false;
		}

		return true;
	}

	return false;
}

template<>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(int)> convertFunction)
{
	if(oXMLStreamReader.attributes().hasAttribute(sAttributeName))
	{
		bool l_bConvertSuccess = false;
		int l_value = oXMLStreamReader.attributes().value(sAttributeName).toInt(&l_bConvertSuccess);

		if(l_bConvertSuccess)
		{
			convertFunction(l_value);
		}
		else
		{
			qWarning() << "Failed to convert the [" << sAttributeName << "] attribute of the theme "<< m_sFilePath;
		}

		return true;
	}

	return false;
}

template<>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(CHyperSpinThemeMedia::EStartingPosition)> convertFunction)
{
	if(oXMLStreamReader.attributes().hasAttribute(sAttributeName))
	{
		QStringRef l_value = oXMLStreamReader.attributes().value(sAttributeName);

		if(l_value == "none")
		{
			convertFunction(CHyperSpinThemeMedia::EStartingPosition::StartingPosition_None);
		}
		else if(l_value == "top")
		{
			convertFunction(CHyperSpinThemeMedia::EStartingPosition::StartingPosition_Top);
		}
		else if(l_value == "bottom")
		{
			convertFunction(CHyperSpinThemeMedia::EStartingPosition::StartingPosition_Bottom);
		}
		else if(l_value == "left")
		{
			convertFunction(CHyperSpinThemeMedia::EStartingPosition::StartingPosition_Left);
		}
		else if(l_value == "right")
		{
			convertFunction(CHyperSpinThemeMedia::EStartingPosition::StartingPosition_Right);
		}
		else
		{
			qWarning() << "Failed to convert the [" << sAttributeName << "] attribute of the theme "<< m_sFilePath;
			return false;
		}

		return true;
	}

	return false;
}

template<>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(CHyperSpinThemeMedia::EAnimationType)> convertFunction)
{
	if(oXMLStreamReader.attributes().hasAttribute(sAttributeName))
	{
		QStringRef l_value = oXMLStreamReader.attributes().value(sAttributeName);

		if(l_value == "none")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_None);
		}
		else if(l_value == "arcgrow")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_ArcGrow);
		}
		else if(l_value == "arcshrink")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_ArcShrink);
		}
		else if(l_value == "blur")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Blur);
		}
		else if(l_value == "bounce")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Bounce);
		}
		else if(l_value == "bouncearound3d")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_BounceAround3D);
		}
		else if(l_value == "bouncerandom")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_BounceRandom);
		}
		else if(l_value == "chase")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Chase);
		}
		else if(l_value == "ease")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Ease);
		}
		else if(l_value == "elastic")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Elastic);
		}
		else if(l_value == "elasticbounce")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_ElasticBounce);
		}
		else if(l_value == "fade")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Fade);
		}
		else if(l_value == "flag")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Flag);
		}
		else if(l_value == "flip")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Flip);
		}
		else if(l_value == "grow")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Grow);
		}
		else if(l_value == "growblur")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_GrowBlur);
		}
		else if(l_value == "growbounce")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_GrowBounce);
		}
		else if(l_value == "growcentershrink")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_GrowCenterShrink);
		}
		else if(l_value == "growx")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_GrowX);
		}
		else if(l_value == "growy")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_GrowY);
		}
		else if(l_value == "pendulum")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Pendulum);
		}
		else if(l_value == "pixelate")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Pixelate);
		}
		else if(l_value == "pixelatezoomout")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_PixelateZoomOut);
		}
		else if(l_value == "rainfloat")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_RainFloat);
		}
		else if(l_value == "scroll")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Scroll);
		}
		else if(l_value == "stripes")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Stripes);
		}
		else if(l_value == "stripes2")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Stripes2);
		}
		else if(l_value == "strobe")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_Strobe);
		}
		else if(l_value == "sweepleft")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_SweepLeft);
		}
		else if(l_value == "sweepright")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_SweepRight);
		}
		else if(l_value == "zoomout")
		{
			convertFunction(CHyperSpinThemeMedia::EAnimationType::AnimationType_ZoomOut);
		}
		else
		{
			qWarning() << "Failed to convert the [" << sAttributeName << "] attribute of the theme "<< m_sFilePath;
			return false;
		}

		return true;
	}

	return false;
}

template<>
bool CHyperSpinTheme::parseAnAttribute(const QXmlStreamReader& oXMLStreamReader, const QString sAttributeName, std::function<void(CHyperSpinThemeMedia::ERestingAnimation)> convertFunction)
{
	if(oXMLStreamReader.attributes().hasAttribute(sAttributeName))
	{
		QStringRef l_value = oXMLStreamReader.attributes().value(sAttributeName);

		if(l_value == "none")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_None);
		}
		else if(l_value == "hover")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_Hover);
		}
		else if(l_value == "hoverhorizontal")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_HoverHorizontal);
		}
		else if(l_value == "hoververtical")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_HoverVertical);
		}
		else if(l_value == "pulse")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_Pulse);
		}
		else if(l_value == "pulsefast")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_PulseFast);
		}
		else if(l_value == "rock")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_Rock);
		}
		else if(l_value == "rockfast")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_RockFast);
		}
		else if(l_value == "spin")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_Spin);
		}
		else if(l_value == "spinslow")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_SpinSlow);
		}
		else if(l_value == "spinfast")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_SpinFast);
		}
		else if(l_value == "squeeze")
		{
			convertFunction(CHyperSpinThemeMedia::ERestingAnimation::RestingAnimation_Squeeze);
		}
		else
		{
			qWarning() << "Failed to convert the [" << sAttributeName << "] attribute of the theme "<< m_sFilePath;
			return false;
		}

		return true;
	}

	return false;
}

bool CHyperSpinTheme::parseATheme()
{
	QFile l_oFile(m_sFilePath);

	if(!l_oFile.open(QFile::ReadOnly| QFile::Text))
	{
		qWarning() << "Cannot open the HyperSpin theme file:" << m_sFilePath << ":" << l_oFile.errorString();
		return false;
	}

	QXmlStreamReader l_oXMLStreamReader;
	l_oXMLStreamReader.setDevice(&l_oFile);

	l_oXMLStreamReader.readNext();

	while (!l_oXMLStreamReader.atEnd())
	{
		if(l_oXMLStreamReader.isStartElement())
		{
			if(l_oXMLStreamReader.name() == "Theme")
			{
				l_oXMLStreamReader.readNext();

				while(l_oXMLStreamReader.isStartElement() == false)
				{
					l_oXMLStreamReader.readNext();
				}

				if(l_oXMLStreamReader.name() == "video")
				{
					CHyperSpinThemeVideo l_oVideo;

					/*if(!parseAnAttribute<float>(l_oXMLStreamReader, "w", std::bind(&CHyperSpinThemeVideo::setWidth, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "h", std::bind(&CHyperSpinThemeVideo::setHeight, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "x", std::bind(&CHyperSpinThemeVideo::setPositionX, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "y", std::bind(&CHyperSpinThemeVideo::setPositionY, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "r", std::bind(&CHyperSpinThemeVideo::setRotation, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "rx", std::bind(&CHyperSpinThemeVideo::setRotationPositionX, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "ry", std::bind(&CHyperSpinThemeVideo::setRotationPositionY, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<bool>(l_oXMLStreamReader, "below", std::bind(&CHyperSpinThemeVideo::setIsBelow, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "overlaybelow", std::bind(&CHyperSpinThemeVideo::setIsOverlayBelow, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "overlayoffsetX", std::bind(&CHyperSpinThemeVideo::setOverlayOffsetX, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "overlayoffsetY", std::bind(&CHyperSpinThemeVideo::setOverlayOffsetY, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "delay", std::bind(&CHyperSpinThemeVideo::setDelay, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "time", std::bind(&CHyperSpinThemeVideo::setTime, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<int>(l_oXMLStreamReader, "bsize", std::bind(&CHyperSpinThemeVideo::setBSize, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<int>(l_oXMLStreamReader, "bsize2", std::bind(&CHyperSpinThemeVideo::setBSize2, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<int>(l_oXMLStreamReader, "bsize3", std::bind(&CHyperSpinThemeVideo::setBSize3, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<int>(l_oXMLStreamReader, "bcolor", std::bind(&CHyperSpinThemeVideo::setBColor, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<int>(l_oXMLStreamReader, "bcolor2", std::bind(&CHyperSpinThemeVideo::setBColor2, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<int>(l_oXMLStreamReader, "bcolor3", std::bind(&CHyperSpinThemeVideo::setBColor3, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<CHyperSpinThemeMedia::EStartingPosition>(l_oXMLStreamReader, "start", std::bind(&CHyperSpinThemeVideo::setStartingPosition, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<CHyperSpinThemeMedia::EAnimationType>(l_oXMLStreamReader, "type", std::bind(&CHyperSpinThemeVideo::setAnimationType, l_oVideo, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<CHyperSpinThemeMedia::ERestingAnimation>(l_oXMLStreamReader, "resting", std::bind(&CHyperSpinThemeVideo::setRestingAnimation, l_oVideo, std::placeholders::_1)))
					{

					}*/

					m_oHyperSpinVideo = l_oVideo;
				}

				if(l_oXMLStreamReader.name() == "artwork1" || l_oXMLStreamReader.name() == "artwork2" || l_oXMLStreamReader.name() == "artwork3" || l_oXMLStreamReader.name() == "artwork4")
				{
					CHyperSpinThemeArtwork l_oArtwork;

					/*if(!parseAnAttribute<float>(l_oXMLStreamReader, "w", std::bind(&CHyperSpinThemeArtwork::setWidth, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "h", std::bind(&CHyperSpinThemeArtwork::setHeight, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "x", std::bind(&CHyperSpinThemeArtwork::setPositionX, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "y", std::bind(&CHyperSpinThemeArtwork::setPositionY, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "r", std::bind(&CHyperSpinThemeArtwork::setRotation, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "rx", std::bind(&CHyperSpinThemeArtwork::setRotationPositionX, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "ry", std::bind(&CHyperSpinThemeArtwork::setRotationPositionY, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "delay", std::bind(&CHyperSpinThemeArtwork::setDelay, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<float>(l_oXMLStreamReader, "time", std::bind(&CHyperSpinThemeArtwork::setTime, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<CHyperSpinThemeMedia::EAnimationType>(l_oXMLStreamReader, "type", std::bind(&CHyperSpinThemeArtwork::setAnimationType, l_oArtwork, std::placeholders::_1)))
					{

					}

					if(!parseAnAttribute<CHyperSpinThemeMedia::ERestingAnimation>(l_oXMLStreamReader, "resting", std::bind(&CHyperSpinThemeArtwork::setRestingAnimation, l_oArtwork, std::placeholders::_1)))
					{

					}*/

					m_voHyperSpinArtworks.push_back(l_oArtwork);
				}

				if(l_oXMLStreamReader.name() == "particle")
				{
				}

				if(l_oXMLStreamReader.isEndElement() && l_oXMLStreamReader.name() == "Theme")
				{

				}
			}
		}
		// do processing
	}

	l_oFile.close();

	if (l_oXMLStreamReader.hasError())
	{
		qWarning() << "Failed to parse the HyperSpin theme file:" << m_sFilePath << ":" << l_oXMLStreamReader.errorString();
		return false;
	}

	return true;
}



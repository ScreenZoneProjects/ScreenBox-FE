/*
*      Copyright (C) 2015 Team ScreenZone
*      http://screenzone.fr
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QString>
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <map>
#include "XmlParser.hpp"

int XmlParser::read(const char * filePath)
{
	QFileInfo pathInfo = QFileInfo(QString(filePath));
	QDir dirPath = pathInfo.absoluteDir();

	if (!dirPath.exists())
	{
		return XmlParser::ERR::NO_DIRECTORY;
	}

	if(!pathInfo.exists())
	{
		return XmlParser::ERR::NO_FILE;
	}

	QFile file(pathInfo.absoluteFilePath());

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return XmlParser::ERR::NO_READ_ACCESS;
	}

	m_doc.setContent(&file);
	file.close();

	QDomElement menu = m_doc.firstChildElement("menu");
	QDomElement theme = m_doc.firstChildElement("Theme");

	if(!menu.isNull())
	{
		return fillGamesList(menu);
	}
	else if (!theme.isNull())
	{
		return fillThemeMap(theme);
	}
	else
	{
		return XmlParser::ERR::UNKNOWN_FILE;
	}
}

QDomDocument XmlParser::getDocument()
{
	return m_doc;
}

QList < std::map<QString, QString> > XmlParser::getMenu()
{
	return m_menuGamesList;
}

std::map<QString, std::map<QString, QString> > XmlParser::getTheme()
{
	return m_themeMap;
}

int XmlParser::fillGamesList(QDomElement menu)
{

	QDomElement gameElt = menu.firstChildElement("game");

	for(; !gameElt.isNull(); gameElt = gameElt.nextSiblingElement("game"))
	{
		std::map<QString, QString> gMap;

		QString gName = gameElt.attribute("name");
		gMap["name"] = gName;

		QString gIndex = gameElt.attribute("index","");
		gMap["index"] = gIndex;

		QString gImage = gameElt.attribute("image","");
		gMap["image"] = gImage;

		QDomElement gDescription = gameElt.firstChildElement("description");
		if (!gDescription.isNull())
		{
			gMap["description"] = gDescription.text();
		}

		QDomElement gCloneOf = gameElt.firstChildElement("cloneof");
		if (!gCloneOf.isNull()){
			gMap["cloneof"] = gCloneOf.text();
		}

		QDomElement gCrc = gameElt.firstChildElement("crc");
		if (!gCrc.isNull())
		{
			gMap["crc"] = gCrc.text();
		}

		QDomElement gManufacturer = gameElt.firstChildElement("manufacturer");
		if (!gManufacturer.isNull())
		{
			gMap["manufacturer"] = gManufacturer.text();
		}

		QDomElement gYear = gameElt.firstChildElement("year");
		if (!gYear.isNull())
		{
			gMap["year"] = gYear.text();
		}

		QDomElement gGenre = gameElt.firstChildElement("genre");
		if (!gGenre.isNull())
		{
			gMap["genre"] = gGenre.text();
		}

		QDomElement gRating = gameElt.firstChildElement("rating");
		if (!gRating.isNull())
		{
			gMap["rating"] = gRating.text();
		}

		QDomElement gEnabled = gameElt.firstChildElement("enabled");
		if (!gEnabled.isNull())
		{
			gMap["enabled"] = gEnabled.text();
		}

		m_menuGamesList.append(gMap);

	}

	return XmlParser::ERR::NONE;
}

int XmlParser::fillThemeMap(QDomElement theme)
{

	std::map<QString, std::map<QString, QString> > themeNodesList;

	QDomElement video = theme.firstChildElement("video");
	if (!video.isNull())
	{
		themeNodesList["video"] = populateThemeNode(video, "video");
	}

	QDomElement artwork1 = theme.firstChildElement("artwork1");
	if (!artwork1.isNull())
	{
		themeNodesList["artwork1"] = populateThemeNode(video, "artwork");
	}

	QDomElement artwork2 = theme.firstChildElement("artwork2");
	if (!artwork2.isNull())
	{
		themeNodesList["artwork2"] = populateThemeNode(video, "artwork");
	}

	QDomElement artwork3 = theme.firstChildElement("artwork3");
	if (!artwork3.isNull())
	{
		themeNodesList["artwork3"] = populateThemeNode(video, "artwork");
	}

	QDomElement artwork4 = theme.firstChildElement("artwork4");
	if (!artwork4.isNull())
	{
		themeNodesList["artwork4"] = populateThemeNode(video, "artwork");
	}

	m_themeMap = themeNodesList;

	return XmlParser::ERR::NONE;
}

std::map<QString, QString> XmlParser::populateThemeNode(QDomElement element, QString type)
{
	std::map<QString, QString> map;
	map["x"] = element.attribute("x", "0");
	map["y"] = element.attribute("y", "0");
	map["r"] = element.attribute("r", "0");
	map["time"] = element.attribute("time", "0");
	map["type"] = element.attribute("type", "ease");
	map["start"] = element.attribute("start", "left");

	if (type == "video")
	{
		map["w"] = element.attribute("w", "0");
		map["h"] = element.attribute("h", "0");
		map["delay"] = element.attribute("delay", "0");
		map["bcolor"] = element.attribute("bcolor", "0x000000");
		map["bsize"] = element.attribute("bsize", "0");
	}
	else if (type == "artwork")
	{
		map["rest"] = element.attribute("rest", "none");
	}

	return map;
}

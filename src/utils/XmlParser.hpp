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

#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QDomDocument>
#include <QList>
#include <map>

class XmlParser
{
public:

    enum ERR : unsigned int {
        NONE,
        NO_READ_ACCESS,
        NO_FILE,
        NO_DIRECTORY,
        UNKNOWN_FILE
    };

    int read(const char * filePath);

    QDomDocument getDocument();

    QList < std::map<QString, QString> > getMenu();

    std::map<QString, std::map<QString, QString> > getTheme();

private:
    QDomDocument m_doc;
    QList < std::map<QString, QString> > m_menuGamesList;
    std::map<QString, std::map<QString, QString> > m_themeMap;

    int fillGamesList(QDomElement menu);

    int fillThemeMap(QDomElement theme);

    std::map<QString, QString> populateThemeNode(QDomElement element, const char * type);

};

#endif // XMLPARSER_H

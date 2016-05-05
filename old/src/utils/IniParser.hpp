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

#pragma once

#include <map>
#include <QString>

class IniParser
{
private:
    std::map<QString, std::map<QString, QString> > m_iniMap;
    QString m_sectionName;
public:

	enum ERR : unsigned int
	{
        NONE,
        NO_READ_ACCESS,
        NO_FILE,
        NO_DIRECTORY,
        UNKNOWN_FILE,
        NO_WRITE_ACCESS
    };

	/**
     * Read the ini file, and populate the private map variable.
     */
    int read(const QString filePath);


	/**
     * Write the ini file entirely, based on a specific map
     */
    int write(const QString filePath, std::map<QString, std::map<QString, QString> > map);

	/**
     * Get the map variable containing structured version of the ini file
     */
    std::map<QString, std::map<QString, QString> > getMap();

};

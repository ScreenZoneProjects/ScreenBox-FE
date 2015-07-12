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

#ifndef INIPARSER_H
#define INIPARSER_H

#include <map>
#include <string>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

class IniParser
{
private:
    std::string m_sectionName;
    std::map<std::string, std::map<std::string, std::string> > m_iniMap;
public:

    enum ERR : unsigned int
    {
        DUMMY,
        NO_READ_ACESS,
        NO_WRITE_ACESS,
        NO_PATH_ACCESS
    };

    /*
     * Read the ini file, and populate the private map variable.
     */
    int read(const std::string& filePath)
    {
        QFile file(QString(filePath.c_str()));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            return ERR::NO_READ_ACESS;
        }


        QTextStream in(&file);
        m_iniMap.clear();

        while(!in.atEnd())
        {
            std::string line = in.readLine().toStdString();
            if (line.find("[") == 0) {
                line.erase(line.end()-1);
                std::map<std::string, std::string> sectionMap;
                m_sectionName = line.substr(line.find("[")+1, line.find("]")-1);
                m_iniMap[m_sectionName] = sectionMap;
            }
            else
            {
                if (line.size() > 0)
                {
                    std::string entryName = line.substr(0,line.find("="));
                    std::string value = line.substr(line.find("=")+1, line.size());
                    if (entryName == value)
                        value = "";
                    m_iniMap[m_sectionName][entryName] = value;
                }

            }

        }
        file.close();
        return 0;
    };


    /*
     * Write the ini file entirely, based on a specific map
     */
    int write(const std::string& filePath, std::map<std::string, std::map<std::string, std::string> > map)
    {
        QFileInfo pathInfo = QFileInfo(QString(filePath.c_str()));
        QDir dirPath = pathInfo.absoluteDir();
        if(!dirPath.exists())
            if(!QDir().mkpath(pathInfo.absolutePath()))
                return ERR::NO_PATH_ACCESS;
        QFile file(QString(filePath.c_str()));
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return ERR::NO_READ_ACESS;
        }
        QTextStream out(&file);
        for (auto it0 = map.begin(); it0 != map.end(); it0++)
        {
            out << "[" << it0->first.c_str() << "]" << "\n";

            std::map<std::string, std::string> sectionMap = it0->second;

            for (auto it1 = sectionMap.begin(); it1 != sectionMap.end(); it1++)
            {
                out << it1->first.c_str() << "=" << it1->second.c_str() << "\n";
            }
        }
        file.close();
        return 0;
    };

    /*
     * Get the map variable containing structured version of the ini file
     */
    std::map<std::string, std::map<std::string, std::string> > getMap()
    {
        return m_iniMap;
    };

};


#endif // INIPARSER_H

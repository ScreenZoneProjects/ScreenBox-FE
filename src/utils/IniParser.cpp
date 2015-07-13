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

#include <map>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QString>
#include "IniParser.hpp"

#include <iostream>

int IniParser::read(const QString filePath){

    QFileInfo pathInfo = QFileInfo(QString(filePath));
    QDir dirPath = pathInfo.absoluteDir();

    if (!dirPath.exists()){
        std::cout << "no dir" << std::endl;
        return IniParser::ERR::NO_DIRECTORY;
    }

    if(!pathInfo.exists()){
        std::cout << "no file" << std::endl;
        return IniParser::ERR::NO_FILE;
    }

    QFile file(pathInfo.absoluteFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "no access" << std::endl;
        return IniParser::ERR::NO_READ_ACCESS;
    }

    QTextStream in(&file);
    m_iniMap.clear();

    while(!in.atEnd())
    {
        QString line = in.readLine();

        line.remove(QRegExp("/\r?\n|\r/"));

        if (line.indexOf("[") == 0) {
            std::map<QString, QString> sectionMap;
            m_sectionName = line.remove(QChar('[')).remove(QChar(']'));
            m_iniMap[m_sectionName] = sectionMap;
        }
        else
        {
            if (line.size() > 0)
            {
                QStringList keyValue = line.split("=");
                if (keyValue.size() == 2){
                    QString entryName = keyValue.at(0);
                    QString value = keyValue.at(1);
                    std::map <QString, QString> section = m_iniMap[m_sectionName];
                    section[entryName] = value;
                }

            }

        }

    }
    file.close();
    return IniParser::ERR::NONE;
}


int IniParser::write(const QString filePath, std::map<QString, std::map<QString, QString> > map){

    QFileInfo pathInfo = QFileInfo(filePath);
    QDir dirPath = pathInfo.absoluteDir();

    if(!dirPath.exists())
    {
        std::cout << "no dir" << std::endl;
        if(!QDir().mkpath(pathInfo.absolutePath()))
        {
            std::cout << "can't mkdir" << std::endl;
            return IniParser::ERR::NO_WRITE_ACCESS;
        }
    }
    QFile file(pathInfo.absoluteFilePath());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return IniParser::ERR::NO_WRITE_ACCESS;
    }

    QTextStream out(&file);
    for (auto it0 = map.begin(); it0 != map.end(); it0++)
    {
        out << "[" << it0->first << "]" << "\n";

        std::map<QString, QString> sectionMap = it0->second;

        for (auto it1 = sectionMap.begin(); it1 != sectionMap.end(); it1++)
        {
            out << it1->first << "=" << it1->second << "\n";
        }
    }
    file.close();
    return IniParser::ERR::NONE;
}


std::map<QString, std::map<QString, QString> > IniParser::getMap()
{
    return m_iniMap;
}

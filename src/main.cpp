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

#include <QApplication>
#include <QMessageBox>
#include <QQmlApplicationEngine>

#include "core/Frontend.hpp"
#include "utils/AppIntegrity.hpp"
#include "core/Settings.hpp"

int main(int argc, char *argv[])
{
	QGuiApplication l_oApp(argc, argv);

	QQmlApplicationEngine l_oQMLApplicationEngine;
	l_oQMLApplicationEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));

   /* Settings settings;
    AppIntegrity ai(settings);

	if(ai.getStatus() == AppIntegrity::ERROR)
	{
        QMessageBox alert(QMessageBox::Icon::Critical,"Error","Error(s) found in your application directories !");
        alert.setInformativeText("Error code : ");
        alert.setDetailedText(ai.getDetails());
        alert.exec();
        return -1;
	}*/

	//Frontend frontend;
	//frontend.show();

	return l_oApp.exec();
}



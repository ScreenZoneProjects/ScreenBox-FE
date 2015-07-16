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

#include "core/Frontend.hpp"
#include "utils/AppIntegrity.hpp"
#include "core/Settings.hpp"
#include <QApplication>
#include <QMessageBox>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    Settings settings;
    AppIntegrity ai(settings);

    application.setApplicationName("ScreenFlow");
    application.setApplicationDisplayName(QString("ScreenFlow v")+settings.Frontend("Main","Version"));
    application.setApplicationVersion(settings.Frontend("Main","Version"));
    application.setOrganizationDomain("sreenzone.fr");
    application.setOrganizationName("ScreenZone");

    if(settings.Frontend("Optimizer","CPU_Priority") != "normal"){
        QThread::currentThread()->setPriority(QThread::HighPriority);
    }

    if(ai.getStatus() == AppIntegrity::ERROR){
        QMessageBox alert(QMessageBox::Icon::Critical,"Error","Error(s) found in your application directories !");
        alert.setInformativeText("Error code : ");
        alert.setDetailedText(ai.getDetails());
        alert.exec();
        return -1;
    }

    Frontend frontend(settings);

    if(settings.Frontend("Resolution","FullScreen") == "true"){
        frontend.showFullScreen();
    }else {
        frontend.show();
    }

    return application.exec();
}



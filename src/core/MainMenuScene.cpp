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

#include "MainMenuScene.hpp"
#include <QDir>
#include "Wheel.hpp"
#include <QKeyEvent>

MainMenuScene::MainMenuScene(Settings settings, QObject * parent) : QGraphicsScene(parent)
{
    m_pointedSystem = settings.Frontend("Main","Last_System");
    m_settings = settings;
    connect(this,SIGNAL(overToSystemMenu(QString)),parent,SLOT(goToSystemMenu(QString)));
    connect(this,SIGNAL(overToExitMenu()),parent,SLOT(goToExitMenu()));
    connect(this,SIGNAL(overToQuit()),parent,SLOT(quitApplication()));
    connect(this,SIGNAL(overToShutdown()),parent,SLOT(shutdownMachine()));
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));

    QFileInfoList wheelImgList = QDir("Media/Main Menu/Images/Wheel").entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries);
    QGraphicsItem * mainMenuWheel = new Wheel(wheelImgList,m_settings);
    addItem(mainMenuWheel);
    mainMenuWheel->setRotation(90);


}

MainMenuScene::~MainMenuScene(){

}

void MainMenuScene::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_Return){
        emit overToSystemMenu(m_pointedSystem);
    }
    else if (event->key() == Qt::Key_Escape
             && m_settings.Frontend("Main","Enable_Exit") == "true") {
        if(m_settings.Frontend("Main","Enable_Exit_Menu") == "true") {
            emit overToExitMenu();
        }
        else if (m_settings.Frontend("Main","Exit_Action") == "exit") {
            emit overToQuit();
        }
        else {
            emit overToShutdown();
        }
    }
}


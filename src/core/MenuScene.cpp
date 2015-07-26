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

#include "MenuScene.hpp"
#include <QDir>
#include <QKeyEvent>
#include <iostream>

MenuScene::MenuScene(QString sectionName, Settings settings, QObject * parent) : QGraphicsScene(parent)
{
    m_sectionName = sectionName;
    m_isInExitMenu = false;
    if(m_sectionName == "Main Menu"){
        m_pointedItem = settings.Frontend("Main","Last_System");
    }
    m_settings = settings;
    connect(this,SIGNAL(overToMenu(QString)),parent,SLOT(goToMenu(QString)));
    connect(this,SIGNAL(overToQuit()),parent,SLOT(quitApplication()));
    connect(this,SIGNAL(overToShutdown()),parent,SLOT(shutdownMachine()));
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));

    //m_wheel = new Wheel(sectionName);
    //addItem(m_wheel);
}

MenuScene::~MenuScene(){

}

void MenuScene::keyPressEvent(QKeyEvent * event){
    if(event->key() == Qt::Key_Return){
        if (m_isInExitMenu) {
            if (m_selectedExitItem == "yes") {
                emit overToQuit();
            } else {
                hideQuitMenu();
            }
        }
        else {
            emit overToMenu(m_pointedItem);
        }
    }
    else if (event->key() == Qt::Key_Escape){
        if (m_sectionName == "Main Menu") {
            std::cout << "in main menu" << std::endl;
            if(m_isInExitMenu){
               hideQuitMenu();
            }
            else if (m_settings.Frontend("Main","Enable_Exit") == "true"){
                std::cout << "can exit" << std::endl;
                if(m_settings.Frontend("Main","Enable_Exit_Menu") == "true") {
                    std::cout << "have to show exit menu" << std::endl;
                    showQuitMenu();
                }
                else if (m_settings.Frontend("Main","Exit_Action") == "exit") {
                    std::cout << "quit app" << std::endl;
                    emit overToQuit();
                }
                else {
                    emit overToShutdown();
                }
            }
        }
        else {
            emit overToMenu("Main Menu");
        }
    }
    else if (event->key() == Qt::Key_Down) {

    }
    else if (event->key() == Qt::Key_Up) {

    }
}

void MenuScene::showQuitMenu(){
    int windowWidth = m_settings.Frontend("Resolution", "Width").toInt();
    int windowHeight = m_settings.Frontend("Resolution", "Height").toInt();
    m_isInExitMenu = true;
    m_selectedExitItem = m_settings.Frontend("Main", "Exit_Default");
    m_exitMenuItem = new QGraphicsItemGroup();
    QPixmap bgmap("Media/Frontend/Images/Menu_Exit_Background.png");
    QGraphicsPixmapItem * blackBg = new QGraphicsPixmapItem(bgmap);
    m_exitMenuItem->addToGroup(blackBg);
    blackBg->setOpacity(0.75);
    QGraphicsPixmapItem * title = new QGraphicsPixmapItem(QPixmap("Media/Frontend/Images/Text_Exit_WouldYouLikeToExit.png"));
    m_exitMenuItem->addToGroup(title);
    title->setTransformOriginPoint(title->pixmap().width()/2,title->pixmap().height()/2);
    title->setX(windowWidth*0.5);
    title->setY(windowHeight*0.4);
    QGraphicsPixmapItem * yesItem = new QGraphicsPixmapItem(QPixmap("Media/Frontend/Images/Text_Exit_Yes.png"));
    m_exitMenuItem->addToGroup(yesItem);
    yesItem->setTransformOriginPoint(yesItem->pixmap().width()/2,yesItem->pixmap().height()/2);
    yesItem->setX(windowWidth*0.33);
    yesItem->setY(windowHeight*0.75);
    QGraphicsPixmapItem * noItem = new QGraphicsPixmapItem(QPixmap("Media/Frontend/Images/Text_Exit_No.png"));
    m_exitMenuItem->addToGroup(noItem);
    noItem->setTransformOriginPoint(noItem->pixmap().width()/2,noItem->pixmap().height()/2);
    noItem->setX(windowWidth*0.66);
    noItem->setY(windowHeight*0.75);
    QGraphicsPixmapItem * pointerItem = new QGraphicsPixmapItem(QPixmap("Media/Frontend/Images/Menu_Exit_Arrow.png"));
    m_exitMenuItem->addToGroup(pointerItem);
    addItem(m_exitMenuItem);
}

void MenuScene::hideQuitMenu(){
    removeItem(m_exitMenuItem);
    m_isInExitMenu = false;
}




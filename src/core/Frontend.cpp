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

#include "Frontend.hpp"
#include "MenuScene.hpp"
#include "IntroScene.hpp"
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QProcess>

Frontend::Frontend(Settings settings, QWidget *parent)
    : QGraphicsView(parent)
{
    m_settings = settings;

    int width = m_settings.Frontend("Resolution","Width").toInt();
    int height = m_settings.Frontend("Resolution","Height").toInt();
    setFixedSize(width,height);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFocus();

    QString quality = m_settings.Frontend("Optimizer","Quality");

    if(quality == "HIGH"){
        setRenderHints(QPainter::HighQualityAntialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
    } else if (quality == "MEDIUM") {
        setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    } else if (quality == "LOW") {
        setRenderHint(QPainter::NonCosmeticDefaultPen);
    }

    if(m_settings.Frontend("Optimizer","Image_Smoothing") == "true"){
        setRenderHint(QPainter::SmoothPixmapTransform);
    }

    if (m_settings.Frontend("IntroVideo","Use_Intro") == "true"){
        m_currentScene = new IntroScene(m_settings, this);
    }
    else if (m_settings.Frontend("Main","Menu_Mode") == "mutli"){
        m_currentScene = new MenuScene("Main Menu", m_settings, this);
    }
    else {
        QString aloneSystem = m_settings.MainMenu("Main","Single_Mode_Name");
        m_currentScene = new MenuScene(aloneSystem,m_settings,this);
    }
    setScene(m_currentScene);




}

Frontend::~Frontend()
{

}

Settings Frontend::getSettings(){
    return m_settings;
}

void Frontend::goToMenu(QString systemName){
    m_currentScene = new MenuScene(systemName,m_settings,this);
    setScene(m_currentScene);
}

void Frontend::quitApplication(){
    QCoreApplication::quit();
}

void Frontend::shutdownMachine(){
    QProcess::startDetached("shutdown -s -f -t 2");
    QCoreApplication::quit();
}

void Frontend::drawForeground(QPainter *painter, const QRectF &rect){
    if (m_settings.Frontend("Resolution","Scanlines_Active") == "true"){
        float scanAlpha = m_settings.Frontend("Resolution","Scanlines_Alpha").toFloat();
        QString scanImage = m_settings.Frontend("Resolution","Scanlines_Image");
        float scanScale = m_settings.Frontend("Resolution","Scanlines_Scale").toFloat();
        QPixmap img(QString("Media/Frontend/Images/Scanlines/")+scanImage);
        painter->scale(scanScale,scanScale);
        painter->setOpacity(scanAlpha);
        painter->drawTiledPixmap(rect,img);
    }
}

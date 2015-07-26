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

#include "Wheel.hpp"
#include <QGraphicsPixmapItem>
#include <QtMath>
#include <QFileInfo>

Wheel::Wheel(QString sectionName, QList<QString> list, Settings settings, QGraphicsItem * parent)
 : QGraphicsItemGroup(parent)
{
    m_settings = settings;
    m_windowWidth = m_settings.Frontend("Resolution","Width").toInt();
    m_windowHeight = m_settings.Frontend("Resolution","Height").toInt();

    m_wheelOpacity = m_settings.MainMenu("wheel","alpha").toFloat();
    m_smallOpacity = m_settings.MainMenu("wheel","small_alpha").toFloat();
    m_wheelStyle = m_settings.MainMenu("wheel","style");
    m_wheelSpeed = m_settings.MainMenu("wheel", "speed");

    m_vWheel_pos  = m_settings.MainMenu("wheel","vert_wheel_position");
    m_nWheel_largeWidth = m_settings.MainMenu("wheel", "norm_large").toInt();
    m_nWheel_smallWidth = m_settings.MainMenu("wheel", "norm_small").toInt();
    m_vWheel_largeWidth = m_settings.MainMenu("wheel", "vert_large").toInt();
    m_vWheel_smallWidth = m_settings.MainMenu("wheel", "vert_small").toInt();
    m_pWheel_largeWidth = m_settings.MainMenu("wheel", "pin_large").toInt();
    m_pWheel_smallWidth = m_settings.MainMenu("wheel", "pin_small").toInt();
    m_hWheel_largeWidth = m_settings.MainMenu("wheel", "horz_large").toInt();
    m_hWheel_smallWidth = m_settings.MainMenu("wheel", "horz_small").toInt();
    m_hWheel_y = m_settings.MainMenu("wheel","horz_wheel_y").toInt();

    m_text_width = m_settings.MainMenu("wheel", "text_width").toInt();
    m_text_font = m_settings.MainMenu("wheel", "text_font");
    m_text_smallWidth = m_settings.MainMenu("wheel", "small_text_width").toInt();
    m_text_largeWidth = m_settings.MainMenu("wheel", "large_text_width").toInt();
    m_text_strokeSize = m_settings.MainMenu("wheel", "text_stroke_size").toInt();
    m_text_strokeColor = m_settings.MainMenu("wheel", "text_stroke_color");
    m_text_color1 = m_settings.MainMenu("wheel", "text_color1");
    m_text_color2 = m_settings.MainMenu("wheel", "text_color2");
    m_text_color3 = m_settings.MainMenu("wheel", "text_color3");
    m_text_colorRatio = m_settings.MainMenu("wheel", "color_ratio").toInt();
    m_text_shadowDistance = m_settings.MainMenu("wheel", "shadow_distance").toInt();
    m_text_shadowAngle = m_settings.MainMenu("wheel", "shadow_angle").toInt();
    m_text_shadowColor = m_settings.MainMenu("wheel", "shadow_color");
    m_text_shadowAlpha = m_settings.MainMenu("wheel", "shadow_alpha").toFloat();
    m_text_shaodwBlur = m_settings.MainMenu("wheel", "shadow_blur").toFloat();

    for (int i=0; i<list.size(); i++){
        QString testPath = QString("Media/")+sectionName+QString("/Images/Wheel/")+list[i]+QString(".png");
        if(QFileInfo(testPath).exists()) {
            QString absPath = QFileInfo(testPath).absoluteFilePath();
            QPixmap pixmap(absPath);
            QGraphicsPixmapItem item(pixmap);
            //m_itemsList.append(item);
        }
        else {
            QGraphicsTextItem * item = new QGraphicsTextItem(list[i]);
        }
    }



    if (m_wheelStyle == "pin") {
        drawPinWheel();
    }
    else if (m_wheelStyle == "vertical"){
        drawVerticalWheel();
    }
    else if (m_wheelStyle == "horizontal"){
        drawHorizontalWheel();
    }
    else{
        drawNormalWheel();
    }

    /*
    for (int i = 0; i < list.size(); ++i) {
        QString wImgPath = list[i].absoluteFilePath();
        QPixmap pixmap(wImgPath);
        QGraphicsPixmapItem * wImg = new QGraphicsPixmapItem(pixmap);

        addToGroup(wImg);

        wImg->setTransformationMode(Qt::TransformationMode::SmoothTransformation);
        wImg->setTransformOriginPoint(pixmap.width()/2,pixmap.height()/2);
        wImg->setScale(m_windowWidth*0.00075);
        int singleAngle  = int(360/list.size());
        wImg->setRotation(singleAngle*i);
        double wImgRadAngle = qDegreesToRadians(double(singleAngle*i));
        wImg->setX(-1*(ellipseXRay*qCos(wImgRadAngle)));
        wImg->setY(-1*(ellipseYRay*qSin(wImgRadAngle)));

    }*/
}


void Wheel::drawNormalWheel(){
    int wheelRay = int(m_windowWidth*0.4);
}

void Wheel::drawPinWheel(){
    int wheelXRay = int(m_windowWidth*0.5);
    int wheelYRay = int(m_windowHeight*0.25);
}

void Wheel::drawVerticalWheel(){

}

void Wheel::drawHorizontalWheel(){

}

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

Wheel::Wheel(QFileInfoList list, Settings settings, QGraphicsItem * parent)
 : QGraphicsItemGroup(parent)
{
    m_settings = settings;
    int windowWidth = m_settings.Frontend("Resolution","Width").toInt();

    // Declaration des deux longueurs de l'ellipse
    int ellipseXRay = int(windowWidth*0.5);
    int ellipseYRay = int(windowWidth*0.5);


    for (int i = 0; i < list.size(); ++i) {
        QString wImgPath = list[i].absoluteFilePath();
        QPixmap pixmap(wImgPath);
        QGraphicsPixmapItem * wImg = new QGraphicsPixmapItem(pixmap);

        addToGroup(wImg);

        wImg->setTransformationMode(Qt::TransformationMode::SmoothTransformation);
        wImg->setTransformOriginPoint(pixmap.width()/2,pixmap.height()/2);
        wImg->setScale(windowWidth*0.00075);
        int singleAngle  = int(360/list.size());
        wImg->setRotation(singleAngle*i);
        double wImgRadAngle = qDegreesToRadians(double(singleAngle*i));
        wImg->setX(-1*(ellipseXRay*qCos(wImgRadAngle)));
        wImg->setY(-1*(ellipseYRay*qSin(wImgRadAngle)));

        if(i != 0){
            float alpha = m_settings.MainMenu("wheel","alpha").toFloat();
            wImg->setOpacity(alpha);
        }

    }
}


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

#ifndef WHEEL_H
#define WHEEL_H

#include <QList>
#include "Settings.hpp"
#include <QGraphicsItemGroup>

class Wheel : public QGraphicsItemGroup
{
public:
    Wheel(QString sectionName, QList<QString> list, Settings settings, QGraphicsItem * parent = 0);
private:
    //QList<QGraphicsItem> m_itemsList;
    Settings m_settings;
    int m_windowWidth;
    int m_windowHeight;

    float m_wheelOpacity;
    float m_smallOpacity;
    QString m_wheelStyle;
    QString m_wheelSpeed;

    QString m_vWheel_pos;
    int m_nWheel_largeWidth;
    int m_nWheel_smallWidth;
    int m_vWheel_largeWidth;
    int m_vWheel_smallWidth;
    int m_pWheel_largeWidth;
    int m_pWheel_smallWidth;
    int m_hWheel_largeWidth;
    int m_hWheel_smallWidth;
    int m_hWheel_y;

    int m_text_width;
    QString m_text_font;
    int m_text_smallWidth;
    int m_text_largeWidth;
    int m_text_strokeSize;
    QString m_text_strokeColor;
    QString m_text_color1;
    QString m_text_color2;
    QString m_text_color3;
    int m_text_colorRatio;
    int m_text_shadowDistance;
    int m_text_shadowAngle;
    QString m_text_shadowColor;
    float m_text_shadowAlpha;
    float m_text_shaodwBlur;

    void drawNormalWheel();
    void drawPinWheel();
    void drawVerticalWheel();
    void drawHorizontalWheel();
};

#endif // WHEEL_H

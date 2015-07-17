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

#include <QFileInfoList>
#include "Settings.hpp"
#include <QGraphicsItemGroup>

class Wheel : public QGraphicsItemGroup
{
public:
    Wheel(QFileInfoList list, Settings settings, QGraphicsItem * parent = 0);
private:
    Settings m_settings;
};

#endif // WHEEL_H

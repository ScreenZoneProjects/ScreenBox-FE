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

#pragma once

#include <QGraphicsScene>
#include "Settings.hpp"

class MainMenuScene : public QGraphicsScene
{
    Q_OBJECT
signals:
    void overToSystemMenu(QString systemName);
    void overToExitMenu();
    void overToQuit();
    void overToShutdown();
private:
    Settings m_settings;
    QString m_pointedSystem;
public:
    MainMenuScene(Settings settings, QObject *parent = 0);
    ~MainMenuScene();
    void keyPressEvent(QKeyEvent * event);
};

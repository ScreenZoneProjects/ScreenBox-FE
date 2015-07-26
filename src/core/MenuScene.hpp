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
#include "Wheel.hpp"

class MenuScene : public QGraphicsScene
{
    Q_OBJECT
signals:
    void overToMenu(QString itemName);
    void overToQuit();
    void overToShutdown();
private:
    Wheel * m_wheel;
    QGraphicsItemGroup * m_exitMenuItem;
    Settings m_settings;
    bool m_isInExitMenu;
    QString m_selectedExitItem;
    QString m_pointedItem;
    QString m_sectionName;
public:
    MenuScene(QString sectionName, Settings settings, QObject *parent = 0);
    ~MenuScene();
    void keyPressEvent(QKeyEvent * event);
    void showQuitMenu();
    void hideQuitMenu();
};

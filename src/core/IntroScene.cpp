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

#include "IntroScene.hpp"

IntroScene::IntroScene(Settings settings, QObject * parent) : QGraphicsScene(parent)
{
    m_settings = settings;
    connect(this,SIGNAL(over(QString)),parent,SLOT(goToMenu(QString)));
    int width = settings.Frontend("Resolution","Width").toInt();
    int height = settings.Frontend("Resolution","Height").toInt();

    QBrush * brush = new QBrush(Qt::black,Qt::SolidPattern);
    setBackgroundBrush(*brush);

    QFileInfo introFile("Media/Frontend/Video/Intro.mp4");

    if(introFile.exists()){

        m_videoFileName = introFile.absoluteFilePath();
        QGraphicsVideoItem * videoItem = new QGraphicsVideoItem();
        videoItem->setSize(QSizeF(width,height));
        videoItem->setAspectRatioMode(Qt::KeepAspectRatio);
        m_player = new QMediaPlayer();
        m_player->setVideoOutput(videoItem);
        int videoVolume = m_settings.Frontend("Sound","Video_Volume").toInt()*m_settings.Frontend("Sound","Master_Volume").toInt()*0.01;
        m_player->setVolume(videoVolume);
        connect(this,SIGNAL(keyPressed(QKeyEvent *)),m_player,SLOT(stop()));
        connect(m_player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(onHaveToFinish(QMediaPlayer::State)));
        addItem(videoItem);
        videoItem->setFocus();
        QTimer::singleShot(0,this,SLOT(onSceneConstructed()));
    }
}

IntroScene::~IntroScene(){

}

void IntroScene::onSceneConstructed(){
    m_player->setMedia(QUrl(m_videoFileName));
    m_player->play();
}

void IntroScene::onHaveToFinish(QMediaPlayer::State state){
    if (state == QMediaPlayer::State::StoppedState) {
        emit over("Main Menu");
    }
}

void IntroScene::keyPressEvent(QKeyEvent * event){
    if (m_settings.Frontend("IntroVideo","Stop_On_Keypress") == "true"){
        emit keyPressed(event);
    }
    event->accept();
}

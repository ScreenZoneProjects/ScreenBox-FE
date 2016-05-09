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

#include "AppIntegrity.hpp"

#include <QDir>
#include <QString>
#include <QList>
#include <QFileInfo>
#include "../core/Settings.hpp"

AppIntegrity::AppIntegrity(Settings settings)
{
    m_details = "Checking application directory :\n";
    QString currentDir           = QDir().currentPath();
    m_details += currentDir+"\n";
    QString databasesDirPath     = currentDir+QString("/Databases");
    QString emulatorsDirPath     = currentDir+QString("/Emulators");
    QString mediaDirPath         = currentDir+QString("/Media");
    QString modulesDirPath       = currentDir+QString("/Modules");
    QString settingsDirPath      = currentDir+QString("/Settings");

    QString mainMenuDbDirPath    = databasesDirPath+QString("/Main Menu");
    QString mainMenuDbFilePath   = mainMenuDbDirPath+QString("/Main Menu.xml");

    QString frontendMediaDirPath = mediaDirPath+QString("/Frontend");
    QString mainMenuMediaDirPath = mediaDirPath+QString("/Main Menu");

    QString mmImagesMediaDirPath = mainMenuMediaDirPath+QString("/Images");
    QString mmOtherImagesDirPath = mmImagesMediaDirPath+QString("/Other");
    QString wheelPointerImg      = mmOtherImagesDirPath+QString("/Pointer.png");
    QString mmWheelImagesDirPath = mmImagesMediaDirPath+QString("/Wheel");

    QString fImagesMediaDirPath  = frontendMediaDirPath+QString("/Images");
    QString fSoundsMediaDirPath  = frontendMediaDirPath+QString("/Sounds");
    QString fVideoMediaDirPath   = frontendMediaDirPath+QString("/Video");

    if(settings.MainMenu("video default","path") != fVideoMediaDirPath && settings.MainMenu("video default","path") != ""){
        fVideoMediaDirPath = settings.MainMenu("video default","path");
    }

    QString menuExitArrowImg     = fImagesMediaDirPath+QString("/Menu_Exit_Arrow.png");
    QString menuExitBgImg        = fImagesMediaDirPath+QString("/Menu_Exit_Background.png");
    QString menuFavArrowImg      = fImagesMediaDirPath+QString("/Menu_Favorites_Arrow.png");
    QString menuFavBgImg         = fImagesMediaDirPath+QString("/Menu_Favorites_Background.png");
    QString textEditNoImg        = fImagesMediaDirPath+QString("/Text_Exit_No.png");
    QString textEditWouldImg     = fImagesMediaDirPath+QString("/Text_Exit_WouldYouLikeToExit.png");
    QString textEditYesImg       = fImagesMediaDirPath+QString("/Text_Exit_Yes.png");
    QString textFavAddImg        = fImagesMediaDirPath+QString("/Text_Favorites_AddToFavorites.png");
    QString textFavRemImg        = fImagesMediaDirPath+QString("/Text_Favorites_RemoveFromFavorites.png");
    QString textFavViewImg       = fImagesMediaDirPath+QString("/Text_Favorites_ViewFavoriteGames.png");

    QString soundLetterClick     = fSoundsMediaDirPath+QString("/Sound_Letter_Click.mp3");
    QString soundScreenClick     = fSoundsMediaDirPath+QString("/Sound_Screen_Click.mp3");
    QString soundScreenIn        = fSoundsMediaDirPath+QString("/Sound_Screen_In.mp3");
    QString soundScreenOut       = fSoundsMediaDirPath+QString("/Sound_Screen_Out.mp3");
    QString soundWheelIn         = fSoundsMediaDirPath+QString("/Sound_Wheel_In.mp3");
    QString soundWheelJump       = fSoundsMediaDirPath+QString("/Sound_Wheel_Jump.mp3");
    QString soundWheelOut        = fSoundsMediaDirPath+QString("/Sound_Wheel_Out.mp3");
    QString soundWheelClick      = mainMenuMediaDirPath+QString("/Sound/Wheel Click.mp3");


    QString intro                = fVideoMediaDirPath+QString("/Intro.flv");
    QString noVideo              = fVideoMediaDirPath+QString("/No Video.flv");

    QString scanlinesDirPath     = fImagesMediaDirPath+QString("/Scanlines");


	if(!QDir(databasesDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_DATABASES_DIR);
        m_details += "Dir Not Found : " +databasesDirPath + "\n";
    }

	if(!QDir(emulatorsDirPath).exists())
	{
        QDir().mkdir(QString("Emulators"));
    }

	if(!QDir(mediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MEDIA_DIR);
        m_details += "Dir Not Found : " +mediaDirPath + "\n";
    }

	if(!QDir(modulesDirPath).exists())
	{
        QDir().mkdir(QString("Modules"));
    }

	if(!QDir(settingsDirPath).exists())
	{
        QDir().mkdir(QString("Settings"));
    }

	if(!QDir(mainMenuDbDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_DB_DIR);
        m_details += "Dir Not Found : " +mainMenuDbDirPath + "\n";
    }

	if(!QFileInfo(mainMenuDbFilePath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_DB_FILE);
        m_details += "File Not Found : " +mainMenuDbFilePath + "\n";
    }

	if(!QDir(frontendMediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_FRONTEND_MEDIA_DIR);
        m_details += "Dir Not Found : " +frontendMediaDirPath + "\n";
    }

	if(!QDir(mainMenuMediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_MEDIA_DIR);
        m_details += "Dir Not Found : " +mainMenuMediaDirPath + "\n";
    }

	if(!QDir(mmImagesMediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_IMAGES_MEDIA_DIR);
        m_details += "Dir Not Found : " +mmImagesMediaDirPath + "\n";
    }

	if(!QDir(mmOtherImagesDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_OTHER_IMAGES_MEDIA_DIR);
        m_details += "Dir Not Found : " +mmOtherImagesDirPath + "\n";
    }

	if(!QDir(mmWheelImagesDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_WHEEL_IMAGES_MEDIA_DIR);
        m_details += "Dir Not Found : " +mmWheelImagesDirPath + "\n";
    }
	else if(QDir(mmWheelImagesDirPath).entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)
	{
        m_errors.append(AppIntegrity::ERR::NO_MAIN_MENU_WHEEL_IMAGES_PNG);
        m_details += "Wheel Images Not Found : " +mmWheelImagesDirPath + "\n";
    }

	if(!QDir(fImagesMediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_FRONTEND_IMAGES_MEDIA_DIR);
        m_details += "Dir Not Found : " +fImagesMediaDirPath + "\n";
    }

	if(!QDir(fSoundsMediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_FRONTEND_SOUNDS_MEDIA_DIR);
        m_details += "Dir Not Found : " +fSoundsMediaDirPath + "\n";
    }

	if(!QDir(fVideoMediaDirPath).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_FRONTEND_VIDEO_MEDIA_DIR);
        m_details += "Dir Not Found : " +fVideoMediaDirPath + "\n";
    }

	if(settings.Frontend("Main", "Enable_Exit_Menu") == "true")
	{

		if(!QFileInfo(menuExitArrowImg).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Menu_Exit_Arrow_PNG);
            m_details += "File Not Found : " +menuExitArrowImg + "\n";
        }

		if(!QFileInfo(menuExitBgImg).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Menu_Exit_Background_PNG);
            m_details += "File Not Found : " +menuExitBgImg + "\n";
        }

		if(!QFileInfo(textEditNoImg).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Text_Edit_No_PNG);
            m_details += "File Not Found : " +textEditNoImg + "\n";
        }

		if(!QFileInfo(textEditWouldImg).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Text_Edit_WouldYouLikeToExit_PNG);
            m_details += "File Not Found : " +textEditWouldImg + "\n";
        }

		if(!QFileInfo(textEditYesImg).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Text_Edit_Yes_PNG);
            m_details += "File Not Found : " +textEditYesImg + "\n";
        }

    }

	if(!QFileInfo(textFavAddImg).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_Text_Favorites_AddToFavorites_PNG);
        m_details += "File Not Found : " +textFavAddImg + "\n";
    }

	if(!QFileInfo(textFavRemImg).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_Text_Favorites_RemoveFromFavorites_PNG);
        m_details += "File Not Found : " +textFavRemImg + "\n";
    }

	if(!QFileInfo(textFavViewImg).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_Text_Favorites_ViewFavoriteGames_PNG);
        m_details += "File Not Found : " +textFavViewImg + "\n";
    }

	if(!QFileInfo(menuFavArrowImg).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_Menu_Favorites_Arrow_PNG);
        m_details += "File Not Found : " +menuFavArrowImg + "\n";
    }

	if(!QFileInfo(menuFavBgImg).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_Menu_Favorites_Background_PNG);
        m_details += "File Not Found : " +menuFavBgImg + "\n";
    }


	if(settings.MainMenu("sounds","game_sounds") == "true")
	{
		if(!QFileInfo(soundLetterClick).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Sound_Letter_Click_MP3);
            m_details += "File Not Found : " +soundLetterClick + "\n";
        }

		if(!QFileInfo(soundScreenClick).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Sound_Screen_Click_MP3);
            m_details += "File Not Found : " +soundScreenClick + "\n";
        }

		if(!QFileInfo(soundScreenIn).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Sound_Screen_In_MP3);
            m_details += "File Not Found : " +soundScreenIn + "\n";
        }

		if(!QFileInfo(soundScreenOut).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_Sound_Screen_Out_MP3);
            m_details += "File Not Found : " +soundScreenOut + "\n";
        }

		if(settings.MainMenu("sounds","wheel_click") == "true")
		{
			if(!QFileInfo(soundWheelIn).exists())
			{
                m_errors.append(AppIntegrity::ERR::NO_Sound_Wheel_In_MP3);
                m_details += "File Not Found : " +soundWheelIn + "\n";
            }

			if(!QFileInfo(soundWheelJump).exists())
			{
                m_errors.append(AppIntegrity::ERR::NO_Sound_Wheel_Jump_MP3);
                m_details += "File Not Found : " +soundWheelJump + "\n";
            }

			if(!QFileInfo(soundWheelOut).exists())
			{
                m_errors.append(AppIntegrity::ERR::NO_Sound_Wheel_Out_MP3);
                m_details += "File Not Found : " +soundWheelOut + "\n";
            }

			if(!QFileInfo(soundWheelClick).exists())
			{
                 m_errors.append(AppIntegrity::ERR::NO_Sound_Wheel_Click_MP3);
                 m_details += "File Not Found : " +soundWheelClick + "\n";
            }

        }

    }



	if(!QFileInfo(wheelPointerImg).exists())
	{
        m_errors.append(AppIntegrity::ERR::NO_Pointer_PNG);
        m_details += "File Not Found : " +wheelPointerImg + "\n";
    }


	if(settings.Frontend("IntroVideo","Use_intro") == "false")
	{
        if(!QFileInfo(intro).exists()){
            m_errors.append(AppIntegrity::ERR::NO_Intro_FLV);
            m_details += "File Not Found : " +intro + "\n";
        }
    }
	else
	{
		if(!QFileInfo(noVideo).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_No_Video_FLV);
            m_details += "File Not Found : " +noVideo + "\n";
        }
    }

	if(settings.Frontend("Resolution","Scanlines_Active") == "true")
	{
		if(!QDir(scanlinesDirPath).exists())
		{
            m_errors.append(AppIntegrity::ERR::NO_SCANLINES_DIR);
            m_details += "Dir Not Found : " +scanlinesDirPath + "\n";
        }
		else if(QDir(scanlinesDirPath).entryInfoList(QDir::NoDotAndDotDot|QDir::AllEntries).count() == 0)
		{
            m_errors.append(AppIntegrity::ERR::NO_SCANLINES_PNG);
            m_details += "Files Not Found : " +scanlinesDirPath + "\n";
        }
    }

    // Set status when finishing to append errors in stack
	if (m_errors.size() == 0)
	{
        m_status = AppIntegrity::STATUS::OK;
    }
	else
	{
        m_status = AppIntegrity::STATUS::ERROR;
    }
}

int AppIntegrity::getError()
{
    return m_errors.at(0);
}

QList<int> AppIntegrity::getErrors()
{
    return m_errors;
}

int AppIntegrity::getStatus()
{
    return m_status;
}

QString AppIntegrity::getDetails()
{
    return m_details;
}

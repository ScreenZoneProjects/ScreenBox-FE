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

#ifndef APPINTEGRITY_H
#define APPINTEGRITY_H

#include <QList>
#include <QString>

class AppIntegrity
{
private:
    QString m_details;
    QList<int> m_errors;
    int m_status;
public:

    enum STATUS : unsigned int {
        OK,
        ERROR
    };

    enum ERR : unsigned int {


        NO_DATABASES_DIR,
            NO_MAIN_MENU_DB_DIR,
                NO_MAIN_MENU_DB_FILE,


        NO_MEDIA_DIR,

            NO_FRONTEND_MEDIA_DIR,
                NO_FRONTEND_IMAGES_MEDIA_DIR,
                    NO_Menu_Exit_Arrow_PNG,
                    NO_Menu_Exit_Background_PNG,
                    NO_Menu_Favorites_Arrow_PNG,
                    NO_Menu_Favorites_Background_PNG,
                    NO_Text_Edit_No_PNG,
                    NO_Text_Edit_WouldYouLikeToExit_PNG,
                    NO_Text_Edit_Yes_PNG,
                    NO_Text_Favorites_AddToFavorites_PNG,
                    NO_Text_Favorites_RemoveFromFavorites_PNG,
                    NO_Text_Favorites_ViewFavoriteGames_PNG,
                NO_FRONTEND_SOUNDS_MEDIA_DIR,
                    NO_Sound_Letter_Click_MP3,
                    NO_Sound_Screen_Click_MP3,
                    NO_Sound_Screen_In_MP3,
                    NO_Sound_Screen_Out_MP3,
                    NO_Sound_Wheel_In_MP3,
                    NO_Sound_Wheel_Jump_MP3,
                    NO_Sound_Wheel_Out_MP3,
                NO_FRONTEND_VIDEO_MEDIA_DIR,
                    NO_Intro_FLV,
                    NO_No_Video_FLV,

            NO_MAIN_MENU_MEDIA_DIR,
                NO_MAIN_MENU_IMAGES_MEDIA_DIR,
                    NO_MAIN_MENU_OTHER_IMAGES_MEDIA_DIR,
                        NO_Pointer_PNG,
                    NO_MAIN_MENU_WHEEL_IMAGES_MEDIA_DIR,
                        NO_MAIN_MENU_WHEEL_IMAGES_PNG,

    };

    AppIntegrity();

    QList<int> getErrors();

    int getError();

    int getStatus();

    QString getDetails();
};

#endif // APPINTEGRITY_H

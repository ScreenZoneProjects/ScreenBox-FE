#ifndef APPINTEGRITY_H
#define APPINTEGRITY_H

#include <QList>
#include <QString>

class Settings;

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
                    NO_SCANLINES_DIR,
                        NO_SCANLINES_PNG,
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
                NO_Sound_Wheel_Click_MP3,
                NO_MAIN_MENU_IMAGES_MEDIA_DIR,
                    NO_MAIN_MENU_OTHER_IMAGES_MEDIA_DIR,
                        NO_Pointer_PNG,
                    NO_MAIN_MENU_WHEEL_IMAGES_MEDIA_DIR,
                        NO_MAIN_MENU_WHEEL_IMAGES_PNG,

    };

    AppIntegrity(Settings * settings = 0);

    QList<int> getErrors();

    int getError();

    int getStatus();

    QString getDetails();
};

#endif // APPINTEGRITY_H

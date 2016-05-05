TEMPLATE = app

QT += widgets qml quick av avwidgets
CONFIG += c++11

TARGET = ScreenFlow

VERSION = 0.0.0.1
DEFINES += VERSION_STRING=\\\"$$VERSION\\\"
DEFINES += APPLICATION_NAME_STRING=\\\"ScreenFlow\\\"
DEFINES += ORGANIZATION_NAME_STRING=\\\"ScreenZone\\\"
DEFINES += ORGANIZATION_DOMAIN_STRING=\\\"screenzone.fr\\\"
DEFINES += SETDIR_PATH=\\\"/Settings\\\"
DEFINES += OSX_DIR_SUFFIX=\\\"/$${TARGET}.app/Contents/MacOS\\\"

SOURCES += \
    src/settings/AppSettings.cpp \
    src/settings/MenuSettings.cpp \
    src/settings/SystemSettings.cpp \
    src/utils/AppIntegrity.cpp \
    src/main.cpp \
    src/settings/Settings.cpp \
    src/qml/QuickProcess.cpp \
    src/qml/QuickFrontend.cpp \
    src/qml/QuickScene.cpp \
    src/qml/QuickSettings.cpp \
    src/qml/QuickWheel.cpp \
    src/databases/SystemDatabase.cpp \
    src/databases/GameDatabase.cpp

RESOURCES += $$_PRO_FILE_PWD_/resources/resources.qrc

QML_IMPORT_PATH =

RC_FILE = $$_PRO_FILE_PWD_/resources/win32/ScreenFlow.rc
ICON = $$_PRO_FILE_PWD_/resources/osx/logo.icns
QMAKE_INFO_PLIST = $$_PRO_FILE_PWD_/resources/osx/Info.plist

win32 {
    OUT_PWD = $${_PRO_FILE_PWD_}/build/Windows
}

unix:linux:!macx:!android {
    OUT_PWD = $${_PRO_FILE_PWD_}/build/Linux
}

android {
    OUT_PWD = $${_PRO_FILE_PWD_}/build/Android
}

macx {
    OUT_PWD = $${_PRO_FILE_PWD_}/build/MacOSX
}

CONFIG(debug, debug|release) {
    DESTDIR = $${OUT_PWD}/debug
} else {
    DESTDIR = $${OUT_PWD}/release
}

OBJECTS_DIR = $${DESTDIR}/.obj
MOC_DIR = $${DESTDIR}/.moc
RCC_DIR = $${DESTDIR}/.rcc
UI_DIR = $${DESTDIR}/.ui

HEADERS += \
    src/settings/AppSettings.h \
    src/settings/MenuSettings.h \
    src/settings/SystemSettings.h \
    src/utils/AppIntegrity.h \
    src/settings/Settings.h \
    src/qml/QuickSettings.h \
    src/qml/QuickProcess.h \
    src/qml/QuickFrontend.h \
    src/qml/QuickScene.h \
    src/qml/QuickWheel.h \
    src/databases/SystemDatabase.h \
    src/databases/GameDatabase.h

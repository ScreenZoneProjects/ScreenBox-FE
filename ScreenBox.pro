TEMPLATE = app

QT += widgets qml quick av websockets xmlpatterns
CONFIG += c++11

TARGET = ScreenBox



VERSION = 1.0.0
DEFINES += VERSION_STRING=\\\"$$VERSION\\\"
DEFINES += APPLICATION_NAME_STRING=\\\"$${TARGET}\\\"
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
    src/qml/QuickSettings.cpp

RESOURCES += $$_PRO_FILE_PWD_/resources/resources.qrc

RC_FILE = $${_PRO_FILE_PWD_}/resources/win32/$${TARGET}.rc
ICON = $${_PRO_FILE_PWD_}/resources/osx/logo.icns
QMAKE_INFO_PLIST = $${_PRO_FILE_PWD_}/resources/osx/Info.plist

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
    QML_IMPORT_TRACE = 1
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
    src/utils/actionscriptkeys.h

OTHER_FILES += \
    resources/qml/CoverFlow/CoverflowScene.qml \
    resources/qml/Grid/GridScene.qml \
    resources/qml/Exit/ExitMenu.qml \
    resources/qml/Intro/IntroScene.qml \
    resources/qml/main.qml \
    resources/qml/Scripts/Utils.js \
    resources/qml/Wheel/WheelScene.qml \
    resources/qml/Wheel/Theme.qml \
    resources/qml/Wheel/Wheel.qml \
    resources/qml/Wheel/Special.qml

DISTFILES += \
    resources/qml/Special.qml \
    resources/xsd/mainMenu.xsd \
    resources/xsd/systemMenu.xsd \
    resources/qml/Exit/qmldir \
    resources/qml/Grid/qmldir \
    resources/qml/Intro/qmldir \
    resources/qml/Scripts/qmldir \
    resources/qml/CoverFlow/qmldir \
    resources/qml/Wheel/qmldir \
    resources/win32/logo.ico \
    resources/win32/ScreenBox.rc

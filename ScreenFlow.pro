#
#      Copyright (C) 2015 Team ScreenZone
#      http://screenzone.fr
#
#  This Program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2, or (at your option)
#  any later version.
#
#  This Program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with XBMC; see the file COPYING.  If not, see
#  <http://www.gnu.org/licenses/>.
#
#

QT += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScreenFlow
TEMPLATE = app

CONFIG += c++11

SOURCES += src/main.cpp\
    src/Frontend.cpp \
    src/CRom.cpp \
    src/CGame.cpp \
    src/CGenre.cpp \
    src/CRegion.cpp \
    src/CDeveloper.cpp \
    src/CSystem.cpp \
    src/CManufacturer.cpp \
    src/CPlatform.cpp \
    src/CHyperSpinTheme.cpp \
    src/CFranchise.cpp \
    src/CRocketLauncher.cpp \
    src/CHyperSpinThemeVideo.cpp \
    src/CHyperSpinThemeArtwork.cpp \
    src/CHyperSpinThemeParticle.cpp \
    src/CHyperSpinThemeMedia.cpp

HEADERS  += \
    src/CRom.hpp \
    src/CGame.hpp \
    src/CGenre.hpp \
    src/CRegion.hpp \
    src/CDeveloper.hpp \
    src/CSystem.hpp \
    src/CManufacturer.hpp \
    src/CPlatform.hpp \
    src/Frontend.hpp \
    src/CHyperSpinTheme.hpp \
    src/CFranchise.hpp \
    src/CRocketLauncher.hpp \
    src/CHyperSpinThemeVideo.hpp \
    src/CHyperSpinThemeArtwork.hpp \
    src/CHyperSpinThemeParticle.hpp \
    src/CHyperSpinThemeMedia.hpp

RESOURCES += \
    Resource.qrc \
    qml.qrc

DISTFILES += \
    MainForm.ui.qml \
    HyperSpinWheel.qml

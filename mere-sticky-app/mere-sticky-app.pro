include(../mere-sticky-lib/mere-sticky-lib.pri)
include(../../mere-widgets/mere-widgets-lib/mere-widgets-lib.pri)
include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)
include(../../mere-config/mere-config-lib/mere-config-lib.pri)

QT      = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = mere-sticky
VERSION = 0.0.1b
TEMPLATE= app

DEFINES += APP_CODE=\\\"sticky\\\"
DEFINES += APP_NAME=\\\"$$TARGET\\\"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += src/main.cpp \
    src/merestickyapp.cpp \
    src/merestickywin.cpp \
    src/merestickymore.cpp \
    src/merestickynote.cpp \
    src/merestickytitle.cpp \
    src/merestickythemeaction.cpp \
    src/merestickytitlewidget.cpp \
    src/merestickymorewidget.cpp \
    src/merestickynotewidget.cpp \
    src/merestickytitleleftcontrolwidget.cpp \
    src/merestickytitlerightcontrolwidget.cpp

HEADERS += \
    src/merestickyapp.h \
    src/merestickywin.h \
    src/merestickymore.h \
    src/merestickynote.h \
    src/merestickytitle.h \
    src/merestickythemeaction.h \
    src/merestickytitlewidget.h \
    src/merestickymorewidget.h \
    src/merestickynotewidget.h \
    src/merestickytitleleftcontrolwidget.h \
    src/merestickytitlerightcontrolwidget.h

RESOURCES += \
    res/sticky.qrc

DESTDIR = $$PWD/../lib
INCLUDEPATH += /usr/local/include

#
# Install
#
unix{
    target.path = /usr/local/bin
    INSTALLS += target
}

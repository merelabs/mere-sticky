include(../mere-sticky-lib/mere-sticky-lib.pri)
#include(../../mere-widgets/mere-widgets-lib/mere-widgets-lib.pri)
#include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)
#include(../../mere-store/mere-store-lib/mere-store-lib.pri)
#include(../../mere-config/mere-config-lib/mere-config-lib.pri)

QT += core
QT += gui
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = mere-sticky
#TARGET  = chirkut
VERSION = 0.0.1b
TEMPLATE= app

DEFINES += APP_CODE=\\\"sticky\\\"
DEFINES += APP_NAME=\\\"$$TARGET\\\"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += src/main.cpp \
    src/checklistwidget.cpp \
    src/noteeditor.cpp \
    src/notewidget.cpp \
    src/searchwidget.cpp \
    src/stickyapp.cpp \
    src/stickywin.cpp \
    src/taskview.cpp \
    src/taskwidget.cpp \
    src/themeaction.cpp \
    src/themepicker.cpp \
    src/winheader.cpp

HEADERS += \
    src/checklistwidget.h \
    src/noteeditor.h \
    src/notewidget.h \
    src/searchwidget.h \
    src/stickyapp.h \
    src/stickywin.h \
    src/taskview.h \
    src/taskwidget.h \
    src/themeaction.h \
    src/themepicker.h \
    src/winheader.h

RESOURCES += \
    res/sticky.qrc

#OTHER_FILES += \
#    ../etc/sticky.conf

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib
LIBS += -lmere-store
LIBS += -lmere-utils -lmere-widgets
#
# Install
#
unix{
    target.path = /usr/local/bin
    INSTALLS += target
}

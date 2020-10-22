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
    src/issuelineview.cpp \
    src/issueview.cpp \
    src/noteeditor.cpp \
    src/searchview.cpp \
    src/stickyapp.cpp \
    src/stickywin.cpp \
    src/stickywinheader.cpp \
    src/stickywinwrapper.cpp \
    src/tasklistview.cpp \
    src/taskview.cpp \
    src/taskwidget.cpp \
    src/themeaction.cpp \
    src/themelistwidget.cpp \
    src/themepicker.cpp \
    src/themeview.cpp

HEADERS += \
    src/issuelineview.h \
    src/issueview.h \
    src/noteeditor.h \
    src/searchview.h \
    src/stickyapp.h \
    src/stickywin.h \
    src/stickywinheader.h \
    src/stickywinwrapper.h \
    src/tasklistview.h \
    src/taskview.h \
    src/taskwidget.h \
    src/themeaction.h \
    src/themelistwidget.h \
    src/themepicker.h \
    src/themeview.h

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

include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)
include(../../mere-config/mere-config-lib/mere-config-lib.pri)

QT      = core gui

CONFIG += c++11
CONFIG += SHARED

TARGET   = mere-sticky
VERSION  = 0.0.1
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_STICKY_LIB

SOURCES += \
    src/meresticky.cpp \
    src/merestickyconfig.cpp \
    src/merestickytheme.cpp \
    src/merestickythemegroup.cpp \
    src/merestickythemeunit.cpp

HEADERS += \
    src/merestickyconfig.h \
    src/merestickyglobal.h \
    src/meresticky.h \
    src/merestickytheme.h \ \
    src/merestickythemegroup.h \
    src/merestickythemeunit.h

DESTDIR = $$PWD/../lib
LIBS += -lmere-utils -lmere-config
INCLUDEPATH += $$PWD/../include
INCLUDEPATH += /usr/local/include

defineTest(copy) {
    source = $$1
    target = $$2

    for(file, source) {
        sdir = $${dirname(file)}
        sdir = $$replace(sdir, "src", "")
        path = $${target}$${sdir}

        QMAKE_POST_LINK += $$QMAKE_MKDIR $$quote($$path) $$escape_expand(\\n\\t)
        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$file) $$quote($$path) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

#copy($$HEADERS, $$PWD/../include/mere/sticky)
#
# Install
#
unix {
    target.path = /usr/local/lib
    INSTALLS += target

    INSTALL_PREFIX = /usr/local/include/mere/sticky
    for(header, HEADERS) {
        sdir = $${dirname(header)}
        sdir = $$replace(sdir, "src", "")
        path = $${INSTALL_PREFIX}$${sdir}

        eval(headers_$${path}.files += $$header)
        eval(headers_$${path}.path = $$path)
        eval(INSTALLS *= headers_$${path})
    }
}

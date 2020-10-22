include(../../mere-utils/mere-utils-lib/mere-utils-lib.pri)
#include(../../mere-utils/mere-utils-lib/mere-store-lib.pri)
#include(../../mere-config/mere-config-lib/mere-config-lib.pri)

QT      = core
CONFIG += c++11
CONFIG += SHARED

TARGET   = mere-sticky
VERSION  = 0.0.1
TEMPLATE = lib

DEFINES += QT_DEPRECATED_WARNINGS MERE_STICKY_LIB

SOURCES += \
    src/domain/model/base.cpp \
    src/domain/model/category.cpp \
    src/domain/model/config.cpp \
    src/domain/model/issue.cpp \
    src/domain/model/task.cpp \
    src/domain/model/theme.cpp \
    src/domain/store/basestore.cpp \
    src/domain/store/categorystore.cpp \
    src/domain/store/issuestore.cpp \
    src/domain/store/stickystore.cpp \
    src/domain/store/taskstore.cpp \
    src/domain/store/themestore.cpp \
    src/meresticky.cpp \
    src/service/baseservice.cpp \
    src/service/categoryservice.cpp \
    src/service/issueservice.cpp \
    src/service/searchservice.cpp \
    src/service/stickyservice.cpp \
    src/service/taskservice.cpp \
    src/service/themeservice.cpp

HEADERS += \
    src/domain/model/base.h \
    src/domain/model/category.h \
    src/domain/model/config.h \
    src/domain/model/issue.h \
    src/domain/model/task.h \
    src/domain/model/theme.h \
    src/domain/store/basestore.h \
    src/domain/store/categorystore.h \
    src/domain/store/issuestore.h \
    src/domain/store/stickystore.h \
    src/domain/store/taskstore.h \
    src/domain/store/themestore.h \
    src/meresticky.h \
    src/service/baseservice.h \
    src/service/categoryservice.h \
    src/service/issueservice.h \
    src/service/searchservice.h \
    src/service/stickyservice.h \
    src/service/taskservice.h \
    src/service/themeservice.h \
    src/stickyglobal.h

INCLUDEPATH += /usr/local/include

#LIBS += -lmere-utils
LIBS += -lmere-store

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

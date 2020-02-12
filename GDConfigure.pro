TEMPLATE = app
TARGET = GDConfigure
win32: CONFIG(debug,debug|release): TARGET = $${TARGET}d

CONFIG(debug,debug|release): DESTDIR += $$PWD/debug
CONFIG(release,debug|release): DESTDIR += $$PWD/release

VERSION = 1.0.0
win32 {
    RC_ICONS = GrimDawn.ico
    RC_LANG = 0x0004
    QMAKE_TARGET_PRODUCT = "GDConfigure"
    QMAKE_TARGET_DESCRIPTION = "GDConfigure"
    QMAKE_TARGET_COMPANY = "Grim Dawn Chinese Translation Group"
    QMAKE_TARGET_COPYRIGHT = "Copyright (C) 2020-2040 "$${QMAKE_TARGET_COMPANY}

    DEPLOYMENT_OPTS += --force
    DEPLOYMENT_OPTS += --no-translations
    DEPLOYMENT_OPTS += --no-svg
    DEPLOYMENT_OPTS += --no-angle
    DEPLOYMENT_OPTS += --no-opengl-sw
    DEPLOYMENT_OPTS += --no-system-d3d-compiler

    CONFIG(debug,debug|release): DEPLOYMENT_OPTS += --debug
    CONFIG(release,debug|release): DEPLOYMENT_OPTS += --release

    QMAKE_POST_LINK = windeployqt $${DEPLOYMENT_OPTS} $$DESTDIR
}

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
greaterThan(QT_MINOR_VERSION, 13): CONFIG += windeployqt

QMAKE_CXXFLAGS += -std=c++0x

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(debug,debug|release): DEFINES += DEBUG_MODE

BUILD_DIR = $${PWD}/.tmp
OBJECTS_DIR += $$BUILD_DIR/objects
MOC_DIR += $$BUILD_DIR
RCC_DIR += $$BUILD_DIR
UI_DIR  += $$BUILD_DIR

INCLUDEPATH += $$UI_DIR

SOURCES += \
    grimdawn.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Job.h \
    grimdawn.h \
    mainwindow.h \
    utils.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    GDConfigure_zh_CN.ts

RESOURCES += \
    Resources.qrc

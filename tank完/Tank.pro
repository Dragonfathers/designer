#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T10:29:41
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tank
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wanwu.cpp \
    tank.cpp \
    bullet.cpp \
    boom.cpp \
    mapcell.cpp \
    gamemap.cpp \
    status.cpp

HEADERS  += mainwindow.h \
    wanwu.h \
    tank.h \
    bullet.h \
    boom.h \
    mapcell.h \
    gamemap.h \
    main.h \
    status.h

RESOURCES += \
    mytank.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T19:45:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += multimedia widgets

TARGET = TablicaPunktowa
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

DISTFILES += \
    horn.wav

#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T17:08:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIElicottero
TEMPLATE = app


SOURCES += main.cpp\
        controlwindow.cpp \
    stick.cpp \
    button.cpp

HEADERS  += controlwindow.h \
    stick.h \
    button.h

FORMS    += controlwindow.ui

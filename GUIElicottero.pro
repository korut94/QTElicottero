#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T17:08:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4):

QT += widgets
QT += serialport

TARGET = GUIElicottero
TEMPLATE = app


SOURCES += main.cpp\
        controlwindow.cpp \
    stick.cpp \
    button.cpp \
    screencamera.cpp \
    crediti.cpp \
    seriale.cpp

HEADERS  += controlwindow.h \
    stick.h \
    button.h \
    screencamera.h \
    crediti.h \
    seriale.h

FORMS    += controlwindow.ui \
    crediti.ui

OTHER_FILES += \
    GUIObject/BaseJoy.png \
    GUIObject/frecciaDX.gif \
    GUIObject/frecciaLX.gif \
    GUIObject/frecciaRX.gif \
    GUIObject/frecciaTX.gif \
    GUIObject/JoyStick.png

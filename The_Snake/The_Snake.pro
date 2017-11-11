#-------------------------------------------------
#
# Project created by QtCreator 2017-09-18T19:54:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = The_Snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snake.cpp \
    food.cpp

HEADERS  += mainwindow.h \
    snake.h \
    food.h

FORMS    += mainwindow.ui

unix {
CONFIG+= link_pkgconfig
PKGCONFIG += sfml-window
}

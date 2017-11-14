QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
LIBS += -L/usr/local/lib -lgtest


TARGET = TGTs
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
            ../The_Snake/mainwindow.cpp \
                ../The_Snake/snake.cpp \
                     ../The_Snake/food.cpp

HEADERS +=  ../The_Snake/mainwindow.h \
                 ../The_Snake/snake.h \
                        ../The_Snake/food.h


FORMS    += ../The_Snake/mainwindow.ui

win32 {
    INCLUDEPATH += ../path/to/gtest/includes
    LIBS += -L../path/to/gtest/libraries -lgtest_dll \
}

unix {
CONFIG+= link_pkgconfig
PKGCONFIG += sfml-window
}

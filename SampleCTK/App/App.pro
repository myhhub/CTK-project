QT += core
QT -= gui

TARGET = App
CONFIG += console
TEMPLATE = app
DESTDIR = $$OUT_PWD/../bin

include($$PWD/../CTK.pri)

SOURCES += main.cpp

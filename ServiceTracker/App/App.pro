QT += core
QT -= gui

TARGET = ServiceTracker
CONFIG += console
TEMPLATE = app
DESTDIR = $$OUT_PWD/../bin

include($$PWD/../CTK.pri)

SOURCES += main.cpp

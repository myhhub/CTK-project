QT += core gui widgets

TEMPLATE = app
CONFIG += console
TARGET = App
DESTDIR = $$OUT_PWD/../bin

include($$PWD/../CTK.pri)

SOURCES += \
    main.cpp

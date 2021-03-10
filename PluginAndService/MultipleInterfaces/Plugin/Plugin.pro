QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = Greet
DESTDIR = $$OUT_PWD/../bin/plugins

include($$PWD/../CTK.pri)

HEADERS += \
    greet_service.h \
    greet_impl.h \
    greet_activator.h

SOURCES += \
    greet_impl.cpp \
    greet_activator.cpp

RESOURCES += Resource.qrc

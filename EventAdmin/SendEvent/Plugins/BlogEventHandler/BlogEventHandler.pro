QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogEventHandler
DESTDIR = $$OUT_PWD/../../bin/plugins

include($$PWD/../../CTK.pri)

HEADERS += \
    blog_event_handler.h \
    blog_event_handler_activator.h

SOURCES += \
    blog_event_handler_activator.cpp

RESOURCES += Resource.qrc

QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogEventHandlerUsingSlots
DESTDIR = $$OUT_PWD/../../bin/plugins

include($$PWD/../../CTK.pri)

HEADERS += \
    blog_event_handler_using_slots.h \
    blog_event_handler_using_slots_activator.h

SOURCES += \
    blog_event_handler_using_slots_activator.cpp

RESOURCES += Resource.qrc

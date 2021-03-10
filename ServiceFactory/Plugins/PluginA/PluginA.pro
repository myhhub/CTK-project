QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = PluginA
DESTDIR = $$OUT_PWD/../../bin/plugins

include($$PWD/../../CTK.pri)

HEADERS += \
    plugin_a_service.h \
    plugin_a_impl.h \
    plugin_a_activator.h

SOURCES += \
    plugin_a_activator.cpp \
    plugin_a_impl.cpp

RESOURCES += Resource.qrc

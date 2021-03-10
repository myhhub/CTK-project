QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogManagerUsingSignals
DESTDIR = $$OUT_PWD/../../bin/plugins

include($$PWD/../../CTK.pri)

HEADERS += \
    blog_manager_using_signals.h \
    blog_manager_using_signals_activator.h

SOURCES += \
    blog_manager_using_signals.cpp \
    blog_manager_using_signals_activator.cpp

RESOURCES += Resource.qrc

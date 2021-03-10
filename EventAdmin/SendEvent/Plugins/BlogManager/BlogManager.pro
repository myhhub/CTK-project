QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = BlogManager
DESTDIR = $$OUT_PWD/../../bin/plugins

include($$PWD/../../CTK.pri)

HEADERS += \
    blog_manager.h \
    blog_manager_activator.h


SOURCES += \
    blog_manager.cpp \
    blog_manager_activator.cpp

RESOURCES += Resource.qrc

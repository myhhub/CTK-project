QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = WelcomeQt
DESTDIR = $$OUT_PWD/../../bin/plugins

include($$PWD/../../CTK.pri)

HEADERS += \
    welcome_qt_impl.h \
    welcome_qt_activator.h

SOURCES += \
    welcome_qt_impl.cpp \
    welcome_qt_activator.cpp

RESOURCES += Resource.qrc

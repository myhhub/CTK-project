QT += core
QT -= gui

TEMPLATE = lib
CONFIG += plugin
TARGET = HelloCTK
DESTDIR = $$OUT_PWD/../bin/plugins

include($$PWD/../CTK.pri)

file.path = $$DESTDIR
file.files = MANIFEST.MF
INSTALLS += file

RESOURCES += \
    Resource.qrc

HEADERS += \
    hello_activator.h \
    hello_impl.h \
    hello_service.h

SOURCES += \
    hello_activator.cpp \
    hello_impl.cpp

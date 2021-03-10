QT += core
QT -= gui

TARGET = EventListener
CONFIG += console
TEMPLATE = app

# CTK 安装路径
CTK_INSTALL_PATH = $$PWD/../../CTKInstall

# CTK 插件相关库所在路径（例如：CTKCore.lib、CTKPluginFramework.lib）
CTK_LIB_PATH = $$CTK_INSTALL_PATH/lib/ctk-0.1

# CTK 插件相关头文件所在路径（例如：ctkPluginFramework.h）
CTK_INCLUDE_PATH = $$CTK_INSTALL_PATH/include/ctk-0.1

# CTK 插件相关头文件所在路径（主要因为用到了 service 相关东西）
CTK_INCLUDE_FRAMEWORK_PATH = $$PWD/../../CTK-master/Libs/PluginFramework

LIBS += -L$$CTK_LIB_PATH -lCTKCore -lCTKPluginFramework

INCLUDEPATH += $$CTK_INCLUDE_PATH \
               $$CTK_INCLUDE_FRAMEWORK_PATH

SOURCES += main.cpp \
    event_listener.cpp

HEADERS += \
    event_listener.h

QT += core gui widgets

TARGET = UseCTKWidgets
TEMPLATE = app

# CTK 安装路径
CTK_INSTALL_PATH = $$PWD/../../CTKInstall

# CTK 相关库所在路径（例如：CTKCore.lib、CTKWidgets.lib）
CTK_LIB_PATH = $$CTK_INSTALL_PATH/lib/ctk-0.1

# CTK 相关头文件所在路径（例如：ctkPluginFramework.h）
CTK_INCLUDE_PATH = $$CTK_INSTALL_PATH/include/ctk-0.1

# 相关库文件（CTKCore.lib、CTKWidgets.lib）
LIBS += -L$$CTK_LIB_PATH -lCTKCore -lCTKWidgets

INCLUDEPATH += $$CTK_INCLUDE_PATH

SOURCES += main.cpp

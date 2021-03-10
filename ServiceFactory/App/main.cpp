#include <QCoreApplication>
#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    ctkPluginFrameworkFactory frameWorkFactory;
    QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
    try {
        // 初始化并启动插件框架
        framework->init();
        framework->start();
        qDebug() << "CTK Plugin Framework start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to initialize the plugin framework: " << e.what();
        return -1;
    }

    // 获取插件上下文
    ctkPluginContext* context = framework->getPluginContext();

    // 获取插件所在位置
    QString path = QCoreApplication::applicationDirPath() + "/plugins";

    // 启动插件 Hello
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/Hello.dll"));
        plugin->start();
        qDebug() << "Hello plugin start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to start Hello" << e.what();
    }

    // 启动插件 A
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/PluginA.dll"));
        plugin->start();
        qDebug() << "PluginA start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to start PluginA" << e.what();
    }

    // 启动插件 B
    try {
       QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/PluginB.dll"));
        plugin->start();
        qDebug() << "PluginB start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to start PluginB" << e.what();
    }

    return app.exec();
}

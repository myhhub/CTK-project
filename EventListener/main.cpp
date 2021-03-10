#include <QCoreApplication>
#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "event_listener.h"

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

    // 事件监听
    EventListener listener;
    context->connectFrameworkListener(&listener, SLOT(onFrameworkEvent(ctkPluginFrameworkEvent)));
    context->connectPluginListener(&listener, SLOT(onPluginEvent(ctkPluginEvent)));
    // 过滤 ctkEventAdmin 服务
    // QString filter = QString("(%1=%2)").arg(ctkPluginConstants::OBJECTCLASS).arg("org.commontk.eventadmin");
    context->connectServiceListener(&listener, "onServiceEvent"); //, filter);

    // 获取插件所在位置
    QString path = QCoreApplication::applicationDirPath() + "/plugins";

    // 遍历路径下的所有插件
    QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
    while (itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            // 安装插件
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
            // 启动插件
            plugin->start(ctkPlugin::START_TRANSIENT);
        } catch (const ctkPluginException &e) {
            return -1;
        }
    }

    framework->stop();

    return app.exec();
}

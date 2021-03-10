#include <QCoreApplication>
#include <QDirIterator>
#include <QtDebug>

#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>

#include "../Service/welcome_service.h"

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

    qDebug() << "********************";

    // 获取插件上下文
    ctkPluginContext* context = framework->getPluginContext();

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
            qDebug() << "Plugin start:" << QFileInfo(strPlugin).fileName();
        } catch (const ctkPluginException &e) {
            qDebug() << "Failed to start plugin" << e.what();
            return -1;
        }
    }

    qDebug() << "********************";

    // 1. 获取所有服务
    QList<ctkServiceReference> refs = context->getServiceReferences<WelcomeService>();
    foreach (ctkServiceReference ref, refs) {
        if (ref) {
            qDebug() << "Name:" << ref.getProperty("name").toString()
                     <<  "Service ranking:" << ref.getProperty(ctkPluginConstants::SERVICE_RANKING).toLongLong()
                      << "Service id:" << ref.getProperty(ctkPluginConstants::SERVICE_ID).toLongLong();
            WelcomeService* service = qobject_cast<WelcomeService *>(context->getService(ref));
            if (service != Q_NULLPTR)
                service->welcome();
        }
    }

    qDebug() << "********************";

    // 2. 使用过滤表达式，获取感兴趣的服务
    refs = context->getServiceReferences<WelcomeService>("(&(name=CTK))");
    foreach (ctkServiceReference ref, refs) {
        if (ref) {
            WelcomeService* service = qobject_cast<WelcomeService *>(context->getService(ref));
            if (service != Q_NULLPTR)
                service->welcome();
        }
    }

    qDebug() << "********************";

    // 3. 获取某一个服务（由 Service Ranking 和 Service ID 决定）
    ctkServiceReference ref = context->getServiceReference<WelcomeService>();
    if (ref) {
        WelcomeService* service = qobject_cast<WelcomeService *>(context->getService(ref));
        if (service != Q_NULLPTR)
            service->welcome();
    }

    return app.exec();
}

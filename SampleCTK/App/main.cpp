#include <QCoreApplication>
#include <QDirIterator>
#include <QtDebug>
#include <ctkPluginFrameworkFactory.h>
#include <ctkPluginFramework.h>
#include <ctkPluginException.h>
#include <ctkPluginContext.h>
#include "../HelloCTK/hello_service.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    app.setApplicationName("SampleCTK");//给框架创建名称，Linux下没有会报错
    ctkPluginFrameworkFactory frameWorkFactory;
    QSharedPointer<ctkPluginFramework> framework = frameWorkFactory.getFramework();
    try {
        // 初始化并启动插件框架
        framework->init();
        framework->start();
        qDebug() << "CTK Plugin Framework start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to initialize the plugin framework: " << e.what();
        qDebug() << e.message() << e.getType();
        return -1;
    }

    // 获取插件上下文
    ctkPluginContext* context = framework->getPluginContext();

    // 获取插件所在位置
    QString path = QCoreApplication::applicationDirPath() + "/plugins";
    qDebug() << path;

    // 遍历路径下的所有插件
    QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
    while (itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            // 安装插件
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
            // 启动插件
            plugin->start(ctkPlugin::START_TRANSIENT);
            qDebug() << "Plugin start ...";
        } catch (const ctkPluginException &e) {
            qDebug() << "Failed to install plugin" << e.what();
            return -1;
        }
    }

    // 获取服务引用
    ctkServiceReference reference = context->getServiceReference<HelloService>();
    if (reference) {
        // 获取指定 ctkServiceReference 引用的服务对象
        HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
        if (service != Q_NULLPTR) {
            // 调用服务
            service->sayHello();
        }
    }

    return app.exec();
}

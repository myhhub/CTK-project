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

    // 遍历路径下的所有插件
    QDirIterator itPlugin(path, QStringList() << "*.dll" << "*.so", QDir::Files);
    while (itPlugin.hasNext()) {
        QString strPlugin = itPlugin.next();
        try {
            // 安装插件
            QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(strPlugin));
            qDebug() << "Plugin install ...";

            // 获取清单头和值
            QHash<QString, QString> headers = plugin->getHeaders();
            qDebug() << "Headers:" << headers << "\r\n";

            // 获取符号名
            QString symb = plugin->getSymbolicName();
            qDebug() << "Symbolic Name:" << symb << "\r\n";

            // 获取版本号
            ctkVersion version = plugin->getVersion();
            qDebug() << "Version:" << version.toString()
                     << "Major:" << version.getMajor()
                     << "Minor:" << version.getMinor()
                     << "Micro:" << version.getMicro()
                     << "Qualifier:" << version.getQualifier();

            // 启动插件
            //plugin->start(ctkPlugin::START_TRANSIENT);
        } catch (const ctkPluginException &e) {
            qDebug() << "Failed to install plugin" << e.what();
            return -1;
        }
    }

    return app.exec();
}

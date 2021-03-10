#include <QCoreApplication>
#include <QtDebug>
#include <ctkPluginFrameworkLauncher.h>
#include <ctkPluginContext.h>
#include <ctkPluginException.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // 获取插件所在位置
    // 在插件的搜索路径列表中添加一条路径
    ctkPluginFrameworkLauncher::addSearchPath("../../../../CTKInstall/lib/ctk-0.1/plugins");
    // 设置并启动 CTK 插件框架
    ctkPluginFrameworkLauncher::start("org.commontk.eventadmin");
    // 获取插件上下文
    ctkPluginContext* context = ctkPluginFrameworkLauncher::getPluginContext();

    QString path = QCoreApplication::applicationDirPath() + "/plugins";

    // 启动插件 BlogEventHandler
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/BlogEventHandler.dll"));
        plugin->start();
        qDebug() << "BlogEventHandler start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to start BlogEventHandler" << e.what();
    }

     //启动插件 BlogManager
    try {
        QSharedPointer<ctkPlugin> plugin = context->installPlugin(QUrl::fromLocalFile(path + "/BlogManager.dll"));
        plugin->start();
        qDebug() << "BlogManager start ...";
    } catch (const ctkPluginException &e) {
        qDebug() << "Failed to start BlogManager" << e.what();
    }

    // 停止插件
    ctkPluginFrameworkLauncher::stop();

    return app.exec();
}

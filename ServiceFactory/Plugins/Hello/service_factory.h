#ifndef SERVICE_FACTORY_H
#define SERVICE_FACTORY_H

#include <ctkServiceFactory.h>
#include <ctkPluginConstants.h>
#include <ctkVersion.h>
#include "hello_impl.h"

class ServiceFactory : public QObject, public ctkServiceFactory
{
    Q_OBJECT
    Q_INTERFACES(ctkServiceFactory)

public:
    ServiceFactory() : m_counter(0) {}

    // 创建服务对象
    QObject* getService(QSharedPointer<ctkPlugin> plugin, ctkServiceRegistration registration) Q_DECL_OVERRIDE {
        Q_UNUSED(registration)

        qDebug() << "Create object of HelloService for: " << plugin->getSymbolicName();
        m_counter++;
        qDebug() << "Number of plugins using service: " << m_counter;

        QHash<QString, QString> headers = plugin->getHeaders();
        ctkVersion version = ctkVersion::parseVersion(headers.value(ctkPluginConstants::PLUGIN_VERSION));
        QString name = headers.value(ctkPluginConstants::PLUGIN_NAME);

        QObject* hello = getHello(version);
        return hello;
    }

    // 释放服务对象
    void ungetService(QSharedPointer<ctkPlugin> plugin, ctkServiceRegistration registration, QObject* service) Q_DECL_OVERRIDE {
        Q_UNUSED(plugin)
        Q_UNUSED(registration)
        Q_UNUSED(service)

        qDebug() << "Release object of HelloService for: "  << plugin->getSymbolicName();
        m_counter--;
        qDebug() << "Number of plugins using service: "  << m_counter;
    }

private:
    // 根据不同的版本，获取不同的服务
    QObject* getHello(ctkVersion version) {
        if (version.toString().contains("alpha")) {
            return new HelloWorldImpl();
        } else {
            return new HelloCTKImpl();
        }
    }

private:
    int m_counter;  // 计数器
};

#endif // SERVICE_FACTORY_H

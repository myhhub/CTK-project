#include "plugin_a_impl.h"
#include "plugin_a_activator.h"
#include "../Hello/hello_service.h"
#include <ctkPluginContext.h>
#include <QtDebug>

void PluginAActivator::start(ctkPluginContext* context)
{
    m_pPlugin = new PluginAImpl();
    context->registerService<PluginAService>(m_pPlugin);

    // 第一次访问服务
    ctkServiceReference reference = context->getServiceReference<HelloService>();
    if (reference) {
        HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
        if (service != Q_NULLPTR) {
            service->sayHello();
        }

        qDebug() << "The first call: " << service;
    }

    // 第二次访问服务
    reference = context->getServiceReference<HelloService>();
    if (reference) {
        HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
        if (service != Q_NULLPTR) {
            service->sayHello();
        }

        qDebug() << "The second call: " << service;
    }
}

void PluginAActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pPlugin;
    m_pPlugin = Q_NULLPTR;
}

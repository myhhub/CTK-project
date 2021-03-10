#ifndef HELLO_ACTIVATOR_H
#define HELLO_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include <ctkPluginContext.h>
#include "hello_service.h"
#include "service_factory.h"

class HelloActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "HELLO")

public:
    // 注册服务工厂
    void start(ctkPluginContext* context) {
        ServiceFactory *factory = new ServiceFactory();
        context->registerService<HelloService>(factory);
    }

    void stop(ctkPluginContext* context) {
        Q_UNUSED(context)
    }
};

#endif // HELLO_ACTIVATOR_H

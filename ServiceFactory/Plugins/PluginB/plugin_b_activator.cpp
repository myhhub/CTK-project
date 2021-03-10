#include "plugin_b_impl.h"
#include "plugin_b_activator.h"
#include "../Hello/hello_service.h"
#include <ctkPluginContext.h>

void PluginBActivator::start(ctkPluginContext* context)
{
    m_pPlugin = new PluginBImpl();
    context->registerService<PluginBService>(m_pPlugin);

    // 访问服务
    ctkServiceReference reference = context->getServiceReference<HelloService>();
    if (reference) {
        HelloService* service = qobject_cast<HelloService *>(context->getService(reference));
        if (service != Q_NULLPTR) {
            service->sayHello();
        }
    }
}

void PluginBActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pPlugin;
    m_pPlugin = Q_NULLPTR;
}

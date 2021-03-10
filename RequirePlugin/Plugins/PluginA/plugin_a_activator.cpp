#include "plugin_a_impl.h"
#include "plugin_a_activator.h"
#include <ctkPluginContext.h>

void PluginAActivator::start(ctkPluginContext* context)
{
    m_pPlugin = new PluginAImpl();
    context->registerService<PluginAService>(m_pPlugin);
}

void PluginAActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pPlugin;
    m_pPlugin = Q_NULLPTR;
}

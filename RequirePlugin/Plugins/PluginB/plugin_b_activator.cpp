#include "plugin_b_impl.h"
#include "plugin_b_activator.h"
#include <ctkPluginContext.h>

void PluginBActivator::start(ctkPluginContext* context)
{
    m_pPlugin = new PluginBImpl();
    context->registerService<PluginBService>(m_pPlugin);
}

void PluginBActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pPlugin;
    m_pPlugin = Q_NULLPTR;
}

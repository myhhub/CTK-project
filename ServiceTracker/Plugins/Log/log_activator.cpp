#include "log_impl.h"
#include "log_activator.h"
#include <ctkPluginContext.h>
#include <QtDebug>

void LogActivator::start(ctkPluginContext* context)
{
    m_pPlugin = new LogImpl();
    context->registerService<LogService>(m_pPlugin);
}

void LogActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pPlugin;
    m_pPlugin = Q_NULLPTR;
}

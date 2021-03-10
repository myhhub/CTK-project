#include "welcome_qt_impl.h"
#include "welcome_qt_activator.h"
#include <QtDebug>

void WelcomeQtActivator::start(ctkPluginContext* context)
{
    ctkDictionary properties;
    properties.insert(ctkPluginConstants::SERVICE_RANKING, 1);
    properties.insert("name", "Qt");

    m_pImpl = new WelcomeQtImpl();
    context->registerService<WelcomeService>(m_pImpl, properties);
}

void WelcomeQtActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pImpl;
}

#include "greet_impl.h"
#include "greet_activator.h"

void GreetActivator::start(ctkPluginContext* context)
{
    m_pImpl = new GreetImpl();

    // 注册服务
    context->registerService<HelloService>(m_pImpl);
    context->registerService<ByeService>(m_pImpl);
}

void GreetActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pImpl;
}

#include "login_impl.h"
#include "login_activator.h"
#include "service_tracker.h"
#include <ctkPluginContext.h>

void LoginActivator::start(ctkPluginContext* context)
{
    // 开启服务跟踪器
    m_pTracker = new ServiceTracker(context);
    m_pTracker->open();

    m_pPlugin = new LoginImpl(m_pTracker);
    m_registration = context->registerService<LoginService>(m_pPlugin);
}

void LoginActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    // 注销服务
    m_registration.unregister();

    // 关闭服务跟踪器
    m_pTracker->close();

    delete m_pPlugin;
    m_pPlugin = Q_NULLPTR;
}

#ifndef LOGIN_ACTIVATOR_H
#define LOGIN_ACTIVATOR_H

#include <ctkPluginActivator.h>

class LoginImpl;
class ServiceTracker;

class LoginActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "LOGIN")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    LoginImpl *m_pPlugin;
    ServiceTracker* m_pTracker;
    ctkServiceRegistration m_registration;
};

#endif // LOGIN_ACTIVATOR_H

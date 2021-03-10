#ifndef GREET_ACTIVATOR_H
#define GREET_ACTIVATOR_H

#include <ctkPluginActivator.h>

class GreetImpl;

class GreetActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "GREET")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    GreetImpl *m_pImpl;
};

#endif // GREET_ACTIVATOR_H

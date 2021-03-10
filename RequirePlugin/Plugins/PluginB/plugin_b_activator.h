#ifndef PLUGIN_B_ACTIVATOR_H
#define PLUGIN_B_ACTIVATOR_H

#include <ctkPluginActivator.h>

class PluginBImpl;

class PluginBActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PLUGIN_B")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    PluginBImpl *m_pPlugin;
};

#endif // PLUGIN_B_ACTIVATOR_H

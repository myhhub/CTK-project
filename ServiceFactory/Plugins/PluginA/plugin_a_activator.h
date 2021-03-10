#ifndef PLUGIN_A_ACTIVATOR_H
#define PLUGIN_A_ACTIVATOR_H

#include <ctkPluginActivator.h>

class PluginAImpl;

class PluginAActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "PLUGIN_A")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    PluginAImpl *m_pPlugin;
};

#endif // PLUGIN_A_ACTIVATOR_H

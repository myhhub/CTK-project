#ifndef LOG_ACTIVATOR_H
#define LOG_ACTIVATOR_H

#include <ctkPluginActivator.h>

class LogImpl;

class LogActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "LOG")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    LogImpl *m_pPlugin;
};

#endif // LOG_ACTIVATOR_H

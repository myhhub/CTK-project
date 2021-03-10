#ifndef PLUGIN_A_SERVICE_H
#define PLUGIN_A_SERVICE_H

#include <QtPlugin>

class PluginAService
{
public:
    virtual ~PluginAService() {}
    virtual void doSomething() = 0;
};

#define PluginAService_iid "org.commontk.service.demos.PluginAService"
Q_DECLARE_INTERFACE(PluginAService, PluginAService_iid)

#endif // PLUGIN_A_SERVICE_H

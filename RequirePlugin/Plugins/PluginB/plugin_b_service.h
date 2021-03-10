#ifndef PLUGIN_B_SERVICE_H
#define PLUGIN_B_SERVICE_H

#include <QtPlugin>

class PluginBService
{
public:
    virtual ~PluginBService() {}
    virtual void doSomething() = 0;
};

#define PluginBService_iid "org.commontk.service.demos.PluginBService"
Q_DECLARE_INTERFACE(PluginBService, PluginBService_iid)

#endif // PLUGIN_B_SERVICE_H

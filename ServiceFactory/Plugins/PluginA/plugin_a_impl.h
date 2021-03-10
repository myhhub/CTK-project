#ifndef PLUGIN_A_IMPL_H
#define PLUGIN_A_IMPL_H

#include "plugin_a_service.h"
#include <QObject>

class PluginAImpl : public QObject, public PluginAService
{
    Q_OBJECT
    Q_INTERFACES(PluginAService)

public:
    PluginAImpl();
    void doSomething() Q_DECL_OVERRIDE;
};

#endif // PLUGIN_A_IMPL_H

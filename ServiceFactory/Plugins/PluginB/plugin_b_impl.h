#ifndef PLUGIN_B_IMPL_H
#define PLUGIN_B_IMPL_H

#include "plugin_b_service.h"
#include <QObject>

class PluginBImpl : public QObject, public PluginBService
{
    Q_OBJECT
    Q_INTERFACES(PluginBService)

public:
    PluginBImpl();
    void doSomething() Q_DECL_OVERRIDE;
};

#endif // PLUGIN_B_IMPL_H

#ifndef HELLO_ACTIVATOR_H
#define HELLO_ACTIVATOR_H

#include <ctkPluginActivator.h>
#include "hello_service.h"

class HelloActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "HELLO_CTK")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    QScopedPointer<HelloService> s;
};

#endif // HELLO_ACTIVATOR_H

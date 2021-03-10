#ifndef WELCOME_CTK_ACTIVATOR_H
#define WELCOME_CTK_ACTIVATOR_H

#include <ctkPluginActivator.h>

class WelcomeQtImpl;

class WelcomeQtActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "WELCOME_QT")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    WelcomeQtImpl *m_pImpl;
};

#endif // WELCOME_CTK_ACTIVATOR_H

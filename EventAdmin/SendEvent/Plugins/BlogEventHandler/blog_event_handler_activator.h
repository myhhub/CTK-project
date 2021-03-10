#ifndef BLOG_EVENT_HANDLER_ACTIVATOR_H
#define BLOG_EVENT_HANDLER_ACTIVATOR_H

#include <ctkPluginActivator.h>

class BlogEventHandler;

class BlogEventHandlerActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "BLOG_EVENT_HANDLER")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    BlogEventHandler *m_pEventHandler;
};

#endif // BLOG_EVENT_HANDLER_ACTIVATOR_H

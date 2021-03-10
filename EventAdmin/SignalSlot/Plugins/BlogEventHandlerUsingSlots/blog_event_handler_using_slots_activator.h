#ifndef BLOG_EVENT_HANDLER_USING_SLOTS_ACTIVATOR_H
#define BLOG_EVENT_HANDLER_USING_SLOTS_ACTIVATOR_H

#include <ctkPluginActivator.h>

class BlogEventHandlerUsingSlots;

class BlogEventHandlerUsingSlotsActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "BLOG_EVENT_HANDLER_USING_SLOTS")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    BlogEventHandlerUsingSlots *m_pEventHandler;
};

#endif // BLOG_EVENT_HANDLER_USING_SLOTS_ACTIVATOR_H

#ifndef BLOG_MANAGER_USING_SIGNALS_ACTIVATOR_H
#define BLOG_MANAGER_USING_SIGNALS_ACTIVATOR_H

#include <ctkPluginActivator.h>

class BlogManagerUsingSignals;

class BlogManagerUsingSignalsActivator : public QObject, public ctkPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(ctkPluginActivator)
    Q_PLUGIN_METADATA(IID "BLOG_MANAGER_USING_SINGALS")

public:
    void start(ctkPluginContext* context);
    void stop(ctkPluginContext* context);

private:
    BlogManagerUsingSignals *m_pBlogManager;
};

#endif // BLOG_MANAGER_USING_SIGNALS_ACTIVATOR_H

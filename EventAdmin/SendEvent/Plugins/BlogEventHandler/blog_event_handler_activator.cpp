#include "blog_event_handler.h"
#include "blog_event_handler_activator.h"
#include <service/event/ctkEventConstants.h>
#include <QtDebug>

void BlogEventHandlerActivator::start(ctkPluginContext* context)
{
    m_pEventHandler = new BlogEventHandler();

    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC] = "org/commontk/bloggenerator/published";
    props[ctkEventConstants::EVENT_FILTER] = "(author=Waleon)";
    context->registerService<ctkEventHandler>(m_pEventHandler, props);
}

void BlogEventHandlerActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pEventHandler;
}


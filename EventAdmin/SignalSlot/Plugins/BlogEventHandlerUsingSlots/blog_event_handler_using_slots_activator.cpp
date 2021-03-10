#include "blog_event_handler_using_slots.h"
#include "blog_event_handler_using_slots_activator.h"
#include <service/event/ctkEventConstants.h>
#include <service/event/ctkEventAdmin.h>

void BlogEventHandlerUsingSlotsActivator::start(ctkPluginContext* context)
{
    m_pEventHandler = new BlogEventHandlerUsingSlots();

    ctkDictionary props;
    props[ctkEventConstants::EVENT_TOPIC] = "org/commontk/bloggenerator/published";
    ctkServiceReference ref = context->getServiceReference<ctkEventAdmin>();
    if (ref) {
        ctkEventAdmin* eventAdmin = context->getService<ctkEventAdmin>(ref);
        eventAdmin->subscribeSlot(m_pEventHandler, SLOT(onBlogPublished(ctkEvent)), props, Qt::DirectConnection);
    }
}

void BlogEventHandlerUsingSlotsActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pEventHandler;
}

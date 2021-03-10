#include "blog_manager.h"
#include <service/event/ctkEventAdmin.h>
#include <QtDebug>

BlogManager::BlogManager(ctkPluginContext* context)
    : m_pContext(context)
{

}

// 发布事件
void BlogManager::publishBlog(const Blog& blog)
{
    ctkServiceReference ref = m_pContext->getServiceReference<ctkEventAdmin>();
    if (ref) {
        ctkEventAdmin* eventAdmin = m_pContext->getService<ctkEventAdmin>(ref);

        ctkDictionary props;
        props["title"] = blog.title;
        props["content"] = blog.content;
        props["author"] = blog.author;
        ctkEvent event("org/commontk/bloggenerator/published", props);

        qDebug() << "Publisher sends a message, properties:" << props;

        eventAdmin->sendEvent(event);
    }
}

#include "blog_manager_using_signals.h"

BlogManagerUsingSignals::BlogManagerUsingSignals(ctkPluginContext *context)
{
    ctkServiceReference ref = context->getServiceReference<ctkEventAdmin>();
    if (ref) {
        ctkEventAdmin* eventAdmin = context->getService<ctkEventAdmin>(ref);
        // 使用 Qt::DirectConnection 等同于 ctkEventAdmin::sendEvent()
        eventAdmin->publishSignal(this, SIGNAL(blogPublished(ctkDictionary)), "org/commontk/bloggenerator/published", Qt::DirectConnection);
    }
}

// 发布事件
void BlogManagerUsingSignals::publishBlog(const Blog& blog)
{
    ctkDictionary props;
    props["title"] = blog.title;
    props["content"] = blog.content;
    props["author"] = blog.author;

    qDebug() << "Publisher sends a message, properties:" << props;
    emit blogPublished(props);

}

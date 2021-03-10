#include "blog_manager_using_signals.h"
#include "blog_manager_using_signals_activator.h"

void BlogManagerUsingSignalsActivator::start(ctkPluginContext* context)
{
    m_pBlogManager = new BlogManagerUsingSignals(context);

    Blog blog;
    blog.title = "CTK Event Admin";
    blog.content = "This is a simple blog";
    blog.author = "Waleon";

    m_pBlogManager->publishBlog(blog);
}

void BlogManagerUsingSignalsActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pBlogManager;
}

#include "blog_manager.h"
#include "blog_manager_activator.h"
#include <QtDebug>
void BlogManagerActivator::start(ctkPluginContext* context)
{
    m_pBlogManager = new BlogManager(context);

    Blog blog;
    blog.title = "CTK Event Admin";
    blog.content = "This is a simple blog";
    blog.author = "Waleon";
    m_pBlogManager->publishBlog(blog);
}

void BlogManagerActivator::stop(ctkPluginContext* context)
{
    Q_UNUSED(context)

    delete m_pBlogManager;
}

#ifndef BLOG_MANAGER_H
#define BLOG_MANAGER_H

#include <ctkPluginContext.h>

typedef struct Blog_Info {
    QString title;
    QString author;
    QString content;
} Blog;

// 事件发布者
class BlogManager
{
public:
    BlogManager(ctkPluginContext* context);
    // 发布事件
    void publishBlog(const Blog& blog);

private:
    ctkPluginContext* m_pContext;
};

#endif // BLOG_MANAGER_H

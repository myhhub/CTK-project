#ifndef BLOG_MANAGER_USING_SIGNALS_SIGNALS_H
#define BLOG_MANAGER_USING_SIGNALS_SIGNALS_H

#include <QObject>
#include <ctkPluginContext.h>
#include <service/event/ctkEventAdmin.h>

typedef struct Blog_Info {
    QString title;
    QString author;
    QString content;
} Blog;

// 事件发布者
class BlogManagerUsingSignals : public QObject
{
    Q_OBJECT

public:
    BlogManagerUsingSignals(ctkPluginContext* context);
    // 发布事件
    void publishBlog(const Blog& blog);

signals:
    void blogPublished(const ctkDictionary&);
};

#endif // BLOG_MANAGER_USING_SIGNALS_SIGNALS_H

#ifndef BLOG_EVENT_HANDLER_USING_SLOTS_H
#define BLOG_EVENT_HANDLER_USING_SLOTS_H

#include <QObject>
#include <QDebug>
#include <service/event/ctkEvent.h>

// 事件处理程序（订阅者）
class BlogEventHandlerUsingSlots : public QObject
{
    Q_OBJECT

public slots:
    void onBlogPublished(const ctkEvent& event)
    {
        QString title = event.getProperty("title").toString();
        QString content = event.getProperty("content").toString();
        QString author = event.getProperty("author").toString();

        qDebug() << "EventHandler received the message, topic:" << event.getTopic()
                 << "properties:" << "title:" << title << "content:" << content << "author:" << author;
    }
};

#endif // BLOG_EVENT_HANDLER_USING_SLOTS_H

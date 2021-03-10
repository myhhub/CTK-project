#ifndef BLOG_EVENT_HANDLER_H
#define BLOG_EVENT_HANDLER_H

#include <QObject>
#include <service/event/ctkEventHandler.h>

// 事件处理程序（或订阅者）
class BlogEventHandler : public QObject, public ctkEventHandler
{
    Q_OBJECT
    Q_INTERFACES(ctkEventHandler)

public:
    // 处理事件
    void handleEvent(const ctkEvent& event) Q_DECL_OVERRIDE
    {
        QString title = event.getProperty("title").toString();
        QString content = event.getProperty("content").toString();
        QString author = event.getProperty("author").toString();

        qDebug() << "EventHandler received the message, topic:" << event.getTopic()
                 << "properties:" << "title:" << title << "content:" << content << "author:" << author;
    }
};

#endif // BLOG_EVENT_HANDLER_H

#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <QObject>
#include <ctkPluginFrameworkEvent.h>
#include <ctkPluginEvent.h>
#include <ctkServiceEvent.h>

class EventListener : public QObject
{
    Q_OBJECT

public:
    explicit EventListener(QObject *parent = Q_NULLPTR);
    ~EventListener();

public slots:
    // 监听框架事件
    void onFrameworkEvent(const ctkPluginFrameworkEvent& event);
    // 监听插件事件
    void onPluginEvent(const ctkPluginEvent& event);
    // 监听服务事件
    void onServiceEvent(const ctkServiceEvent& event);
};

#endif // EVENT_LISTENER_H

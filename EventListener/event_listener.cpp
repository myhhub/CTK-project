#include "event_listener.h"

EventListener::EventListener(QObject *parent)
    : QObject(parent)
{
}

EventListener::~EventListener()
{
}

// 监听框架事件
void EventListener::onFrameworkEvent(const ctkPluginFrameworkEvent& event)
{
    if (!event.isNull()) {
        QSharedPointer<ctkPlugin> plugin = event.getPlugin();
        qDebug() << "FrameworkEvent: [" << plugin->getSymbolicName() << "]" << event.getType() << event.getErrorString();
    } else {
        qDebug() << "The framework event is null";
    }
}

// 监听插件事件
void EventListener::onPluginEvent(const ctkPluginEvent& event)
{
    if (!event.isNull()) {
        QSharedPointer<ctkPlugin> plugin = event.getPlugin();
        qDebug() << "PluginEvent: [" << plugin->getSymbolicName() << "]" << event.getType();
    } else {
        qDebug() << "The plugin event is null";
    }
}

// 监听服务事件
void EventListener::onServiceEvent(const ctkServiceEvent &event)
{
    if (!event.isNull()) {
        ctkServiceReference ref = event.getServiceReference();
        QSharedPointer<ctkPlugin> plugin = ref.getPlugin();
        qDebug() << "ServiceEvent: [" << event.getType() << "]" << plugin->getSymbolicName() << ref.getUsingPlugins();
    } else {
        qDebug() << "The service event is null";
    }
}

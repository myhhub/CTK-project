#ifndef SERVICE_TRACKER_H
#define SERVICE_TRACKER_H

#include <ctkPluginContext.h>
#include <ctkServiceTracker.h>
#include "../Log/log_service.h"

class ServiceTracker : public ctkServiceTracker<LogService *>
{
public:
    ServiceTracker(ctkPluginContext* context) : ctkServiceTracker<LogService *>(context) {}
    ~ServiceTracker() {}

protected:
    // 在 Service 注册时访问
    LogService* addingService(const ctkServiceReference& reference) Q_DECL_OVERRIDE {
        qDebug() << "Adding service:" << reference.getPlugin()->getSymbolicName();
        // return ctkServiceTracker::addingService(reference);

        LogService* service = (LogService*)(ctkServiceTracker::addingService(reference));
        if (service != Q_NULLPTR) {
            service->debug("Ok");
        }

        return service;
    }

    void modifiedService(const ctkServiceReference& reference, LogService* service) Q_DECL_OVERRIDE {
        qDebug() << "Modified service:" << reference.getPlugin()->getSymbolicName();
        ctkServiceTracker::modifiedService(reference, service);
    }

    void removedService(const ctkServiceReference& reference, LogService* service) Q_DECL_OVERRIDE {
        qDebug() << "Removed service:" << reference.getPlugin()->getSymbolicName();
        ctkServiceTracker::removedService(reference, service);
    }
};

#endif // SERVICE_TRACKER_H

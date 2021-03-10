#include "login_impl.h"
#include "service_tracker.h"

LoginImpl::LoginImpl(ServiceTracker *tracker)
    : m_pTracker(tracker)
{

}

bool LoginImpl::login(const QString& username, const QString& password)
{ 
    LogService* service = (LogService*)(m_pTracker->getService());

    if (QString::compare(username, "root") == 0 && QString::compare(password, "123456") == 0) {
        if (service != Q_NULLPTR)
            service->debug("Login successfully");
        return true;
    } else {
        if (service != Q_NULLPTR)
            service->debug("Login failed");
        return false;
    }
}

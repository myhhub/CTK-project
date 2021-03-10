#ifndef LOG_SERVICE_H
#define LOG_SERVICE_H

#include <QtPlugin>

class LogService
{
public:
    virtual ~LogService() {}
    virtual void debug(QString msg) = 0;
};

#define LogService_iid "org.commontk.service.demos.LogService"
Q_DECLARE_INTERFACE(LogService, LogService_iid)

#endif // LOG_SERVICE_H

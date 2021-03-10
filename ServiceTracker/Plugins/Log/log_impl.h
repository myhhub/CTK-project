#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include "log_service.h"
#include <QObject>

class LogImpl : public QObject, public LogService
{
    Q_OBJECT
    Q_INTERFACES(LogService)

public:
    LogImpl();
    void debug(QString msg) Q_DECL_OVERRIDE;
};

#endif // LOG_IMPL_H

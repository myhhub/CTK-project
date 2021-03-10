#ifndef LOGIN_IMPL_H
#define LOGIN_IMPL_H

#include "login_service.h"
#include <QObject>

class ServiceTracker;

class LoginImpl : public QObject, public LoginService
{
    Q_OBJECT
    Q_INTERFACES(LoginService)

public:
    LoginImpl(ServiceTracker *tracker);
    bool login(const QString& username, const QString& password) Q_DECL_OVERRIDE;

private:
    ServiceTracker *m_pTracker;
};

#endif // LOGIN_IMPL_H

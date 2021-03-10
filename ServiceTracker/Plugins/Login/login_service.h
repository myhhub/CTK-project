#ifndef LOGIN_SERVICE_H
#define LOGIN_SERVICE_H

#include <QtPlugin>

class LoginService
{
public:
    virtual ~LoginService() {}
    virtual bool login(const QString& username, const QString& password) = 0;
};

#define LoginService_iid "org.commontk.service.demos.LoginService"
Q_DECLARE_INTERFACE(LoginService, LoginService_iid)

#endif // LOGIN_SERVICE_H

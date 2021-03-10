#ifndef WELCOME_SERVICE_H
#define WELCOME_SERVICE_H

#include <QtPlugin>

class WelcomeService
{
public:
    virtual ~WelcomeService() {}
    virtual void welcome() = 0;
};

#define WelcomeService_iid "org.commontk.service.demos.WelcomeService"
Q_DECLARE_INTERFACE(WelcomeService, WelcomeService_iid)

#endif // WELCOME_SERVICE_H

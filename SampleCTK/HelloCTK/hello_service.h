#ifndef HELLO_SERVICE_H
#define HELLO_SERVICE_H

#include <QtPlugin>

class HelloService
{
public:
    virtual ~HelloService() {}
    virtual void sayHello() = 0;
};

#define HelloService_iid "org.commontk.service.demos.HelloService"
Q_DECLARE_INTERFACE(HelloService, HelloService_iid)

#endif // HELLO_SERVICE_H

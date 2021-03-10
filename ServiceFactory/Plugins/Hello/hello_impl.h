#ifndef HELLO_IMPL_H
#define HELLO_IMPL_H

#include "hello_service.h"
#include <QObject>
#include <QtDebug>

// HelloWorld
class HelloWorldImpl : public QObject, public HelloService
{
    Q_OBJECT
    Q_INTERFACES(HelloService)

public:
    void sayHello() Q_DECL_OVERRIDE {
        qDebug() << "Hello,World!";
    }
};

// HelloCTK
class HelloCTKImpl : public QObject, public HelloService
{
    Q_OBJECT
    Q_INTERFACES(HelloService)

public:
    void sayHello() Q_DECL_OVERRIDE {
        qDebug() << "Hello,CTK!";
    }
};

#endif // HELLO_IMPL_H

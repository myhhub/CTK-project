#include "greet_impl.h"
#include <QtDebug>

GreetImpl::GreetImpl()
{

}

void GreetImpl::sayHello()
{
    qDebug() << "Hello,CTK!";
}

void GreetImpl::sayBye()
{
    qDebug() << "Bye,CTK!";
}

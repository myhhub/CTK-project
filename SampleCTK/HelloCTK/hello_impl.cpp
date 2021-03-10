#include "hello_impl.h"
#include <ctkPluginContext.h>
#include <QtDebug>

HelloImpl::HelloImpl(ctkPluginContext* context)
{
    context->registerService<HelloService>(this);
}

void HelloImpl::sayHello()
{
    qDebug() << "Hello,CTK!";
}

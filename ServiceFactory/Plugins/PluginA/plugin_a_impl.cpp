#include "plugin_a_impl.h"
#include <QtDebug>

PluginAImpl::PluginAImpl()
{

}

void PluginAImpl::doSomething()
{
    qDebug() << "Do something...A";
}


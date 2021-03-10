#include "plugin_b_impl.h"
#include <QtDebug>

PluginBImpl::PluginBImpl()
{

}

void PluginBImpl::doSomething()
{
    qDebug() << "Do something...B";
}

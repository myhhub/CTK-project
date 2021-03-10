#include "log_impl.h"
#include <QtDebug>

LogImpl::LogImpl()
{

}

void LogImpl::debug(QString msg)
{
    qDebug() << "This is a debug message: " << msg;
}


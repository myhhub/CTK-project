#ifndef WELCOME_QT_IMPL_H
#define WELCOME_QT_IMPL_H

#include "../../Service/welcome_service.h"
#include <QObject>

class ctkPluginContext;

class WelcomeQtImpl : public QObject, public WelcomeService
{
    Q_OBJECT
    Q_INTERFACES(WelcomeService)

public:
    WelcomeQtImpl();
    void welcome() Q_DECL_OVERRIDE;
};

#endif // WELCOME_QT_IMPL_H

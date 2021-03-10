#ifndef WELCOME_CTK_IMPL_H
#define WELCOME_CTK_IMPL_H

#include "../../Service/welcome_service.h"
#include <QObject>

class ctkPluginContext;

class WelcomeCTKImpl : public QObject, public WelcomeService
{
    Q_OBJECT
    Q_INTERFACES(WelcomeService)

public:
    WelcomeCTKImpl();
    void welcome() Q_DECL_OVERRIDE;
};

#endif // WELCOME_CTK_IMPL_H

#ifndef MEREBOARDAPP_H
#define MEREBOARDAPP_H

#include "mere/widgets/meredefaultapp.h"

namespace Mere
{
    namespace Sticky
    {
        #ifdef APP_CODE
        const QString AppCode   = APP_CODE;
        #else
        const QString AppCode   = "sticky";
        #endif

        #ifdef APP_NAME
        const QString AppName   = APP_NAME;
        #else
        const QString AppName   = "mere-sticky";
        #endif

        #ifdef APP_VERSION
        const QString AppVersion= APP_VERSION;
        #else
        const QString AppVersion= "0.0.0b";
        #endif
    }
}


class MereStickyWin;
class MereStickyApp : public MereDefaultApp
{
public:
    ~MereStickyApp();
    MereStickyApp(int &argc, char **argv);

    void init();
    void start();

private:
    MereStickyWin *m_win;
};

#endif // MEREBOARDAPP_H

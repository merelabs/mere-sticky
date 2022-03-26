#ifndef MEREBOARDAPP_H
#define MEREBOARDAPP_H

#include "mere/widgets/defaultapp.h"


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

class StickyWin;
class Issue;
class StickyWinWrapper;

class StickyApp : public Mere::Widgets::DefaultApp
{
public:
    ~StickyApp();
    StickyApp(int &argc, char **argv);

    int init() override;
    void start();

    void newNote();
    void openNote(Issue &issue);
    void closeNote(const Issue &issue);
    void closeNote(const StickyWin &win);

private:
    QList<StickyWin *> m_wins;
    QList<Issue *> m_issues;

    QList<StickyWinWrapper *> m_wrappers;
};

#endif // MEREBOARDAPP_H

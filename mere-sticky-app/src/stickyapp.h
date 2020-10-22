#ifndef MEREBOARDAPP_H
#define MEREBOARDAPP_H

#include "mere/widgets/defaultapp.h"

class StickyWin;
class Issue;
class StickyWinWrapper;

class StickyApp : public Mere::DefaultApp
{
public:
    ~StickyApp();
    StickyApp(int &argc, char **argv);

    void init() override;
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

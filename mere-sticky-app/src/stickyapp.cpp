#include "stickyapp.h"
#include "stickywin.h"
#include "stickywinwrapper.h"

#include "mere/sticky/domain/model/issue.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/domain/store/basestore.h"
#include "mere/sticky/domain/store/themestore.h"
#include "mere/sticky/domain/store/issuestore.h"
#include "mere/sticky/service/baseservice.h"
#include "mere/sticky/service/themeservice.h"

#include <QFile>
#include <QFuture>
#include <QtConcurrent>

StickyApp::~StickyApp()
{
    qDeleteAll(m_wins);
}

StickyApp::StickyApp(int &argc, char **argv)
    : Mere::Widgets::DefaultApp(argc, argv)
{
    setObjectName("StickyNoteApp");
    setAppCode(Mere::Sticky::AppCode.toStdString());
    setApplicationName(Mere::Sticky::AppName);
    setApplicationVersion(Mere::Sticky::AppVersion);
}

int StickyApp::init()
{
    Mere::Widgets::DefaultApp::init();

    {
        //
        Mere::Store::Store *s;
        BaseStore store;
        s = &store;
        int err = s->create();
        if (!err)
        {
            s->close();
        }

        BaseStore issue("issue");
        s = &issue;
        err = s->create();
        if (!err)
        {
            Mere::Store::Index indexTitle;
            indexTitle.setName("title");
            indexTitle.setAttribute("title");
            s->create(indexTitle);

            s->close();
        }

        BaseStore task("task");
        s = &task;
        err = s->create();
        s->close();

        BaseStore theme("theme");
        s = &theme;
        err = s->create();
        if (!err)
        {
            Theme criticalPriority;
            criticalPriority.setName("Critical");
            criticalPriority.setForeground("#ffffff");
            criticalPriority.setBackground("#EF0802");

            Theme highPriority;
            highPriority.setName("High");
            highPriority.setForeground("#ffffff");
            highPriority.setBackground("#F8C400");

            Theme mediumPriority;
            mediumPriority.setName("Medium");
            mediumPriority.setForeground("#ffffff");
            mediumPriority.setBackground("#096CC1");

            Theme normalPriority;
            normalPriority.setName("Normal");
            normalPriority.setForeground("#ffffff");
            normalPriority.setBackground("#00FFFF");

            Theme lowPriority;
            lowPriority.setName("Low");
            lowPriority.setForeground("#ffffff");
            lowPriority.setBackground("#0CA952");

            ThemeService themeService;
            themeService.save(criticalPriority);
            themeService.save(highPriority);
            themeService.save(mediumPriority);
            themeService.save(normalPriority);
            themeService.save(lowPriority);

            s->close();
        }
    }

    QFuture<QList<Issue *> > future = QtConcurrent::run([=]{
        BaseService service;

        QList<Issue *> chirkuts = service.list<IssueStore, Issue>();
        return chirkuts;
    });

    future.waitForFinished();

    QList<Issue *> issues = future.result();
    qDebug() << "Number of Chirkut found:" << issues.size();
    if (issues.isEmpty())
    {
        Issue *issue = new Issue();
        issues.append(issue);
    }

    StickyWin *win = new StickyWin(*issues.first());
    win->init();
    m_wins.append(win);

//    StickyWinWrapper *wrapper = new StickyWinWrapper(*issues.first());
//    wrapper->init();
//    m_wrappers.append(wrapper);

    return 0;
}

void StickyApp::start()
{
    QListIterator<StickyWin *> it(m_wins);
    while (it.hasNext())
    {
        StickyWin *win = it.next();
        if (!win) continue;
        win->show();
    }

//    QListIterator<StickyWinWrapper *> it(m_wrappers);
//    while (it.hasNext())
//    {
//        StickyWinWrapper *wrapper = it.next();
//        if (!wrapper) continue;
//        wrapper->show();
//    }
}

void StickyApp::newNote()
{
    Issue *issue = new Issue();

    StickyWin *win = new StickyWin(*issue);
    win->init();
    win->show();

    m_wins.append(win);
}

void StickyApp::openNote(Issue &issue)
{
    StickyWin *win = new StickyWin(issue);
    win->init();
    win->show();

    m_wins.append(win);
}

void StickyApp::closeNote(const Issue &issue)
{
    QMutableListIterator<Issue *> it(m_issues);
    while (it.hasNext())
    {
        Issue *_issue = it.next();
        if (!_issue) continue;

        if (_issue->id() == issue.id())
        {
            it.remove();
            break;
        }
    }
}

void StickyApp::closeNote(const StickyWin &win)
{
    QMutableListIterator<StickyWin *> it(m_wins);
    while (it.hasNext())
    {
        StickyWin *_win = it.next();
        if (!_win) continue;

        if (_win == &win)
        {
            it.remove();
            break;
        }
    }
}

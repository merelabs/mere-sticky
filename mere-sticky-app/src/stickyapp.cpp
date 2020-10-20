#include "stickyapp.h"
#include "stickywin.h"

#include "mere/sticky/domain/model/chirkut.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/domain/store/basestore.h"
#include "mere/sticky/domain/store/themestore.h"
#include "mere/sticky/domain/store/chirkutstore.h"
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
    : MereDefaultApp(argc, argv)
{
    setObjectName("MereStickyApp");
    setAppCode(Mere::Sticky::AppCode);
    setApplicationName(Mere::Sticky::AppName);
    setApplicationVersion(Mere::Sticky::AppVersion);

    // Apply Styles
    QFile qss(":/sticky/sticky.qss");
    qss.open(QFile::ReadOnly);
    QString style = QLatin1String(qss.readAll());
    setStyleSheet(style);
}

void StickyApp::init()
{
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

        BaseStore chirkut("chirkut");
        s = &chirkut;
        err = s->create();
        if (!err)
        {
            Mere::Store::Index indexTitle;
            indexTitle.setName("title");
            indexTitle.setAttribute("title");
            s->create(indexTitle);

            s->close();
        }

        BaseStore theme("theme");
        s = &theme;
        err = s->create();
        if (!err)
        {
            qDebug()<< " R ASHA UCHIT NA";
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

    QFuture<QList<Chirkut *> > future = QtConcurrent::run([=]{
        BaseService service;

        QList<Chirkut *> chirkuts = service.list<ChirkutStore, Chirkut>();
        return chirkuts;
    });

    future.waitForFinished();

    QList<Chirkut *> chirkuts = future.result();
    qDebug() << "XXXNumber of Chirkut found:" << chirkuts.size();

    MereDefaultApp::init();

    if (chirkuts.isEmpty())
    {
        Chirkut *chirkut = new Chirkut();
        chirkuts.append(chirkut);
    }

    StickyWin *win = new StickyWin(*chirkuts.first());
    win->init();
    m_wins.append(win);
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
}

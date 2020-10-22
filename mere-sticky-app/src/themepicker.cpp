#include "themepicker.h"
#include "themelistwidget.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/domain/store/themestore.h"
#include "mere/sticky/service/themeservice.h"

#include "themeaction.h"

#include <QIcon>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QPushButton>
#include <QWidgetAction>
#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>
#include <QFuture>
#include <QtConcurrent>

ThemePicker::~ThemePicker()
{
}

ThemePicker::ThemePicker(QWidget *parent)
    : QWidget(parent)
{
    setObjectName("MereStickyThemePicker");
//    setStyleSheet("border-radius:8px;");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(1, 1, 1, 1);

    setLayout(layout);

    initUI();
}

void ThemePicker::initUI()
{
    QFuture<QList<Theme *> > future = QtConcurrent::run([=]{
        BaseService service;

        return service.list<ThemeStore, Theme>();
    });

    future.waitForFinished();

    QList<Theme *> themes = future.result();
    if (themes.isEmpty()) return;

    QPushButton *themeMenu = new QPushButton(this);
    themeMenu->setObjectName(QString::fromUtf8("stickyTitleLeftMenu"));
    themeMenu->setFlat(true);
    layout()->addWidget(themeMenu);

    QMenu *priority= new QMenu(this);
    priority->setIcon(QIcon(":/sticky/down.png"));

    QListIterator<Theme *> it(themes);
    while (it.hasNext())
    {
        Theme *theme = it.next();

        ThemeAction *themeOneAction = new ThemeAction(*theme, priority);
        connect(themeOneAction, SIGNAL(triggered(const Theme &)), this, SIGNAL(themeSelected(const Theme &)));
        priority->addAction(themeOneAction);
    }

    priority->addSeparator();

    QWidgetAction *manageThemeAction = new QWidgetAction(priority);
    manageThemeAction->setText("Options");
    connect(manageThemeAction, SIGNAL(triggered(const bool)), this, SLOT(manageTheme()));
    priority->addAction(manageThemeAction);

    themeMenu->setMenu(priority);
}

void ThemePicker::manageTheme()
{
    ThemeListWidget *themeListWidget = new ThemeListWidget();
//    themeListWidget->init();
    themeListWidget->show();
}

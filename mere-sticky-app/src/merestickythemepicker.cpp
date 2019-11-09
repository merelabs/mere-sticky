#include "merestickythemepicker.h"
#include "mere/sticky/merestickytheme.h"
#include "merestickythemeaction.h"

#include <QIcon>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QPushButton>
#include <QWidgetAction>
#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

MereStickyThemePicker::~MereStickyThemePicker()
{
}

MereStickyThemePicker::MereStickyThemePicker(QWidget *parent)
    : QWidget(parent)
{
    setObjectName("MereStickyThemePicker");
//    setStyleSheet("border-radius:8px;");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(1, 1, 1, 1);

    setLayout(layout);

    initUI();
}

void MereStickyThemePicker::initUI()
{
    QPushButton *themeMenu = new QPushButton(this);
    themeMenu->setObjectName(QString::fromUtf8("stickyTitleLeftMenu"));

    themeMenu->setMinimumSize(QSize(16, 16));
    themeMenu->setMaximumSize(QSize(16, 16));
    themeMenu->setFlat(true);

    layout()->addWidget(themeMenu);


//    MereStickyConfig config;
//    MereStickyTheme theme = config.theme();
//    QList<MereStickyThemeGroup> groups = theme.groups();
//    foreach (MereStickyThemeGroup group, groups)
//    {
//        MereStickyThemeUnit unit = group.units();
//        foreach (MereStickyThemeUnit unit, units)
//        {

//        }
//    }

    QMenu *priority= new QMenu(this);
    priority->setIcon(QIcon(":/sticky/down.png"));

    MereStickyTheme *themeOne = new MereStickyTheme(this);
    themeOne->setName("High Priority");
    themeOne->setBackgroundColor(Qt::red);

    MereStickyThemeAction *themeOneAction = new MereStickyThemeAction(themeOne, priority);
    connect(themeOneAction, SIGNAL(triggered(MereStickyTheme *)), this, SIGNAL(themeSelected(MereStickyTheme *)));
    priority->addAction(themeOneAction);

    MereStickyTheme *themeTwo = new MereStickyTheme(this);
    themeTwo->setName("Medium Priority");
    themeTwo->setBackgroundColor(Qt::yellow);

    MereStickyThemeAction *themeTwoAction = new MereStickyThemeAction(themeTwo, priority);
    connect(themeTwoAction, SIGNAL(triggered(MereStickyTheme *)), this, SIGNAL(themeSelected(MereStickyTheme *)));
    priority->addAction(themeTwoAction);

    MereStickyTheme *themeThree = new MereStickyTheme(this);
    themeThree->setName("Low Priority");
    themeThree->setBackgroundColor(Qt::green);

    MereStickyThemeAction *themeThreeAction = new MereStickyThemeAction(themeThree, priority);
    connect(themeThreeAction, SIGNAL(triggered(MereStickyTheme *)), this, SIGNAL(themeSelected(MereStickyTheme *)));
    priority->addAction(themeThreeAction);

    MereStickyTheme *themeFour = new MereStickyTheme(this);
    themeFour->setName("Normal Priority");
    themeFour->setBackgroundColor(Qt::cyan);

    MereStickyThemeAction *themeFourAction = new MereStickyThemeAction(themeFour, priority);
    connect(themeFourAction, SIGNAL(triggered(MereStickyTheme *)), this, SIGNAL(themeSelected(MereStickyTheme *)));
    priority->addAction(themeFourAction);

    themeMenu->setMenu(priority);
}

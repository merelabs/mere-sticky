#include "merestickythemepicker.h"
#include "mere/sticky/merestickytheme.h"
#include "merestickythemeaction.h"

#include <QIcon>
#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QWidgetAction>
#include <QHBoxLayout>

MereStickyThemePicker::~MereStickyThemePicker()
{
}

MereStickyThemePicker::MereStickyThemePicker(QWidget *parent)
    : QWidget(parent)
{
    resize(116, 35);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(1, 1, 1, 1);

    setLayout(layout);

    initUI();
}

void MereStickyThemePicker::initUI()
{
    m_stickyTitleLeftMenu = new QPushButton(this);
    m_stickyTitleLeftMenu->setObjectName(QString::fromUtf8("stickyTitleLeftMenu"));

    m_stickyTitleLeftMenu->setMinimumSize(QSize(16, 16));
    m_stickyTitleLeftMenu->setMaximumSize(QSize(16, 16));
    m_stickyTitleLeftMenu->setFlat(true);

    layout()->addWidget(m_stickyTitleLeftMenu);


//    MereStickyTheme *theme = new MereStickyTheme(this);

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

//    priority->addSeparator();
//    QIcon themeNoteIcon(":/sticky/theme.png");
//    QAction* themeNoteAction = new QAction(themeNoteIcon, tr("&Manage..."), this);
//    priority->addAction(themeNoteAction);

    m_stickyTitleLeftMenu->setMenu(priority);
}

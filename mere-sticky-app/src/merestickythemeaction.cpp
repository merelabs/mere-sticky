#include "merestickythemeaction.h"
#include "mere/sticky/merestickytheme.h"

#include <QUuid>
#include <QEvent>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>

MereStickyThemeAction::~MereStickyThemeAction()
{
    if(m_widget != NULL)
    {
        delete m_widget;
        m_widget = NULL;
    }
}

MereStickyThemeAction::MereStickyThemeAction(QWidget *parent)
    : QWidgetAction(parent),
      m_theme(NULL),
      m_widget(NULL)
{

}

MereStickyThemeAction::MereStickyThemeAction(MereStickyTheme *theme, QWidget *parent)
    : QWidgetAction(parent),
      m_theme(theme)
{
    QString objectName = theme->uid().toString(QUuid::WithoutBraces);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(10, 6, 10, 6);

    m_widget = new QWidget(parent);
    m_widget->setObjectName(objectName);
    m_widget->setStyleSheet("#" + m_widget->objectName() + ":hover { background-color: lightgray;}");
    m_widget->setLayout(layout);

    QWidget *themeColor = new QWidget;
    themeColor->setObjectName(objectName + "-color");
    themeColor->setMinimumSize(QSize(12, 12));
    themeColor->setMaximumSize(QSize(12, 12));
    themeColor->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

//    QPalette palette;
//    palette.setColor(QPalette::Background,  Qt::black);
//    themeColor->setPalette(palette);

    themeColor->setStyleSheet("#" + themeColor->objectName() +"{ border-radius: 6px; background-color:" + m_theme->backgroundColor().name() + ";}");
    layout->addWidget(themeColor);

    QLabel  *themeName = new QLabel(theme->name());
    layout->addWidget(themeName);

    setDefaultWidget(m_widget);

    m_widget->installEventFilter(this);
}

MereStickyTheme* MereStickyThemeAction::theme() const
{
    return m_theme;
}

bool MereStickyThemeAction::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QMouseEvent::MouseButtonRelease)
        emit triggered(m_theme);

    return false;
}

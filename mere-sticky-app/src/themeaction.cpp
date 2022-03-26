#include "themeaction.h"
#include "mere/sticky/domain/model/theme.h"

#include <QUuid>
#include <QEvent>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>

ThemeAction::~ThemeAction()
{
    if(m_widget != NULL)
    {
        delete m_widget;
        m_widget = NULL;
    }
}

ThemeAction::ThemeAction(const Theme &theme, QWidget *parent)
    : QWidgetAction(parent),
      m_theme(theme)
{
    QString objectName = theme.id();//.toString(QUuid::WithoutBraces);

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

    themeColor->setStyleSheet("#" + themeColor->objectName() +"{ border-radius: 6px; background-color:" + m_theme.background() + ";}");
    layout->addWidget(themeColor);

    QLabel  *themeName = new QLabel(theme.name());
    layout->addWidget(themeName);

    setDefaultWidget(m_widget);

    m_widget->installEventFilter(this);
}

const Theme &ThemeAction::theme() const
{
    return m_theme;
}

bool ThemeAction::eventFilter(QObject *object, QEvent *event)
{
    Q_UNUSED(object);

    if (event->type() == QMouseEvent::MouseButtonRelease)
        emit triggered(m_theme);

    return false;
}

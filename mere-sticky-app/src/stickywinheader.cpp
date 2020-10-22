#include "stickywinheader.h"
#include "mere/sticky/domain/model/theme.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "themepicker.h"

#include <QPainter>
#include <QStyleOption>

StickyWinHeader::~StickyWinHeader()
{
}

StickyWinHeader::StickyWinHeader(QWidget *parent)
    : Mere::Widgets::SimpleWinHeader(parent)
{
    setObjectName(QString::fromUtf8("MereStickyWinHeader"));
    setContentsMargins(5, 5, 5, 5);

    initUI();
}

void StickyWinHeader::initLeftPanel()
{
    ThemePicker *themePicker = new ThemePicker(this);
    themePicker->setObjectName("MereStickyThemePicker");
    themePicker->setMinimumSize(QSize(18, 18));
    themePicker->setMaximumSize(QSize(18, 18));
    layout()->addWidget(themePicker);

    connect(themePicker, SIGNAL(themeSelected(const Theme&)), this, SIGNAL(themeSelected(const Theme&)));
}

void StickyWinHeader::initCenterPanel()
{
    m_title = new Mere::Widgets::EditableLabel(this);
    m_title->setObjectName(QString::fromUtf8("MereStickyTitle"));
    m_title->setText(QString::fromUtf8("Mere Sticky Notes"));
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setIndent(0);
    m_title->setOpenExternalLinks(true);

    layout()->addWidget(m_title);
}

void StickyWinHeader::initRightPanel()
{
    Mere::Widgets::SimpleWinHeader::initRightPanel();
}

QString StickyWinHeader::title() const
{
    return m_title->text();
}

void StickyWinHeader::setTitle(const QString &title)
{
    m_title->setText(title);
}

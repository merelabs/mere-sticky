#include "winheader.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/widgets/mereeditablelabel.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "themepicker.h"

#include <QPainter>
#include <QStyleOption>

WinHeader::~WinHeader()
{
}

WinHeader::WinHeader(QWidget *parent)
    : MereSimpleWinHeader(parent)
{
    setObjectName(QString::fromUtf8("MereStickyWinHeader"));

    setMaximumHeight(30);

    QPalette p = palette();
    p.setColor( QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette( p );

    initUI();
}

void WinHeader::initLeftPanel()
{
    ThemePicker *themePicker = new ThemePicker(this);
    themePicker->setObjectName("MereStickyThemePicker");
    themePicker->setMinimumSize(QSize(18, 18));
    themePicker->setMaximumSize(QSize(18, 18));
    layout()->addWidget(themePicker);

    connect(themePicker, SIGNAL(themeSelected(const Theme&)), this, SIGNAL(themeSelected(const Theme&)));
}

void WinHeader::initCenterPanel()
{
    m_title = new MereEditableLabel(this);
    m_title->setObjectName(QString::fromUtf8("MereStickyTitle"));
    m_title->setText(QString::fromUtf8("Mere Sticky Notes"));
    m_title->setAlignment(Qt::AlignCenter);
    m_title->setIndent(0);
    m_title->setOpenExternalLinks(true);

    layout()->addWidget(m_title);
}

void WinHeader::initRightPanel()
{
    MereSimpleWinHeader::initRightPanel();
}

QString WinHeader::title() const
{
    return m_title->text();
}

void WinHeader::setTitle(const QString &title)
{
    m_title->setText(title);
}

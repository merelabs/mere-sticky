#include "merestickywinheader.h"
#include "mere/sticky/merestickytheme.h"
#include "mere/widgets/mereeditablelabel.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "merestickythemepicker.h"

#include <QPainter>
#include <QStyleOption>

MereStickyWinHeader::~MereStickyWinHeader()
{
}

MereStickyWinHeader::MereStickyWinHeader(QWidget *parent)
    : MereSimpleWinHeader(parent)
{
    setObjectName(QString::fromUtf8("MereStickyTitleWidget"));

    setMaximumHeight(30);

    QPalette p = palette();
    p.setColor( QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette( p );

    resize(300, 36);


    initUI();
}

void MereStickyWinHeader::initLeftPanel()
{
    m_stickyThemePickerWidget = new MereStickyThemePicker(this);
    m_stickyThemePickerWidget->setObjectName(QString::fromUtf8("stickyThemePickerWidget"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(m_stickyThemePickerWidget->sizePolicy().hasHeightForWidth());
    m_stickyThemePickerWidget->setSizePolicy(sizePolicy1);
    m_stickyThemePickerWidget->setMinimumSize(QSize(18, 18));
    m_stickyThemePickerWidget->setMaximumSize(QSize(18, 18));
    m_stickyThemePickerWidget->setStyleSheet(QString::fromUtf8("#stickyThemePickerWidget\n"
"{\n"
"border-radious: 8px;\n"
"background-color:white;\n"
"}"));

    layout()->addWidget(m_stickyThemePickerWidget);

    connect(m_stickyThemePickerWidget, SIGNAL(themeSelected(MereStickyTheme*)), this, SIGNAL(themeSelected(MereStickyTheme*)));
}

void MereStickyWinHeader::initCenterPanel()
{
    MereEditableLabel *stickyTitle = new MereEditableLabel(this);
    stickyTitle->setObjectName(QString::fromUtf8("stickyTitle"));
    stickyTitle->setText(QString::fromUtf8("Mere Sticky Notes"));
    stickyTitle->setAlignment(Qt::AlignCenter);
    stickyTitle->setIndent(0);
    stickyTitle->setOpenExternalLinks(true);

    layout()->addWidget(stickyTitle);
}

void MereStickyWinHeader::initRightPanel()
{
    MereSimpleWinHeader::initRightPanel();
}

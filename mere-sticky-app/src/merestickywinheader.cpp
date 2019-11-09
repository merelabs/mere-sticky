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
    MereStickyThemePicker *themePicker = new MereStickyThemePicker(this);
    themePicker->setObjectName("MereStickyThemePicker");
    themePicker->setMinimumSize(QSize(18, 18));
    themePicker->setMaximumSize(QSize(18, 18));
    layout()->addWidget(themePicker);

    connect(themePicker, SIGNAL(themeSelected(MereStickyTheme*)), this, SIGNAL(themeSelected(MereStickyTheme*)));
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

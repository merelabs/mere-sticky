#include "merestickywin.h"
#include "merestickynotewidget.h"
#include "merestickywinheader.h"
#include "mere/sticky/merestickytheme.h"

#include <QMouseEvent>
#include <QVBoxLayout>

MereStickyWin::MereStickyWin(QWidget *parent)
    : MereResizeableWin(parent)
{
    setObjectName(QString::fromUtf8("MereStickyWin"));
    resize(300, 175);

    layout()->setSpacing(0);
    layout()->setContentsMargins(5, 5, 5, 5);
    initUI();
}

void MereStickyWin::initHeaderUI()
{
    stickyTitleWidget = new MereStickyWinHeader(this);
    layout()->addWidget(stickyTitleWidget);
    connect(stickyTitleWidget, SIGNAL(themeSelected(MereStickyTheme *)), this, SLOT(applyTheme(MereStickyTheme *)));
}

void MereStickyWin::initContentUI()
{
    stickyNoteWidget = new MereStickyNoteWidget(this);
    layout()->addWidget(stickyNoteWidget);
}

void MereStickyWin::initFooterUI()
{

}

void MereStickyWin::init()
{

}

void MereStickyWin::applyTheme(MereStickyTheme *theme)
{
//    QColor color = theme->backgroundColor();
//    this->setStyleSheet("#MereStickyWin{background-color:" + color.name() + ";}");
}

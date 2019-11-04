#include "merestickytitlerightcontrolwidget.h"
#include "merestickymorewidget.h"

#include <QHBoxLayout>

MereStickyTitleRightControlWidget::~MereStickyTitleRightControlWidget()
{

}

MereStickyTitleRightControlWidget::MereStickyTitleRightControlWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(292, 41);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(1, 1, 1, 1);
    setLayout(layout);

    initUI();
}

void MereStickyTitleRightControlWidget::initUI()
{
    m_moreWidget = new MereStickyMoreWidget(this);
    m_moreWidget->setMinimumSize(QSize(16, 16));

    layout()->addWidget(m_moreWidget);
}

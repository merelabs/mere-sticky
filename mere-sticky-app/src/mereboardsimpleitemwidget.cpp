#include "mereboardsimpleitemwidget.h"
#include "ui_mereboardsimpleitemwidget.h"

MereBoardSimpleItemWidget::MereBoardSimpleItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MereBoardSimpleItemWidget)
{
    ui->setupUi(this);
}

MereBoardSimpleItemWidget::~MereBoardSimpleItemWidget()
{
    delete ui;
}

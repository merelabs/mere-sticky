#ifndef MEREBOARDSIMPLEITEMWIDGET_H
#define MEREBOARDSIMPLEITEMWIDGET_H

#include <QWidget>

namespace Ui {
class MereBoardSimpleItemWidget;
}

class MereBoardSimpleItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MereBoardSimpleItemWidget(QWidget *parent = 0);
    ~MereBoardSimpleItemWidget();

private:
    Ui::MereBoardSimpleItemWidget *ui;
};

#endif // MEREBOARDSIMPLEITEMWIDGET_H

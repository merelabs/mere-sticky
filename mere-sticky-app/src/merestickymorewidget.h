#ifndef MERESTICKYMOREWIDGET_H
#define MERESTICKYMOREWIDGET_H

#include <QDebug>
#include <QPushButton>
#include <QWidget>

class MereStickyMoreWidget : public QWidget
{
    Q_OBJECT
public:
    ~MereStickyMoreWidget();
    explicit MereStickyMoreWidget(QWidget *parent = 0);

private:
    void initUI();

private slots:
    void setupMoreOption(QPushButton *moreOption);
    void on_moreOption_clicked();

private:
    QPushButton *moreOption;
};

#endif // MERESTICKYMOREWIDGET_H

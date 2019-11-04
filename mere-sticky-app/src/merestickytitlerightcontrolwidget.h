#ifndef MERESTICKYTITLERIGHTCONTROLWIDGET_H
#define MERESTICKYTITLERIGHTCONTROLWIDGET_H

#include <QWidget>

class MereStickyMoreWidget;

class MereStickyTitleRightControlWidget : public QWidget
{
    Q_OBJECT
public:
    ~MereStickyTitleRightControlWidget();
    explicit MereStickyTitleRightControlWidget(QWidget *parent = nullptr);
private:
    void initUI();

private:
        MereStickyMoreWidget *m_moreWidget;
};

#endif // MERESTICKYTITLERIGHTCONTROLWIDGET_H

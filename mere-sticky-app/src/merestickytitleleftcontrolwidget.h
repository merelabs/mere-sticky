#ifndef MERESTICKYTITLELEFTCONTROLWIDGET_H
#define MERESTICKYTITLELEFTCONTROLWIDGET_H

#include <QDebug>
#include <QPushButton>
#include <QWidget>

//namespace Ui {
//class MereStickyTitleLeftControlWidget;
//}

class MereStickyTheme;

class MereStickyTitleLeftControlWidget : public QWidget
{
    Q_OBJECT
public:
    ~MereStickyTitleLeftControlWidget();
    explicit MereStickyTitleLeftControlWidget(QWidget *parent = 0);

private:
    void initUI();

signals:
    void themeCreated(MereStickyTheme *theme);
    void themeSelected(MereStickyTheme *theme);

private:
    QPushButton *m_stickyTitleLeftMenu;
};

#endif // MERESTICKYTITLELEFTCONTROLWIDGET_H

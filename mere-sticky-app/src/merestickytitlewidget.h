#ifndef MERESTICKYTITLEWIDGET_H
#define MERESTICKYTITLEWIDGET_H

#include <QWidget>

//namespace Ui {
//class MereStickyTitleWidget;
//}

class MereStickyTheme;

class MereStickyTitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MereStickyTitleWidget(QWidget *parent = 0);
    ~MereStickyTitleWidget();

signals:
    void themeSelected(MereStickyTheme *theme);

private:
//    Ui::MereStickyTitleWidget *ui;
};

#endif // MERESTICKYTITLEWIDGET_H

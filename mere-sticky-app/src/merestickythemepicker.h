#ifndef MERESTHEMEPICKER_H
#define MERESTHEMEPICKER_H

#include <QPushButton>
#include <QWidget>
#include <QDebug>

class MereStickyTheme;

class MereStickyThemePicker : public QWidget
{
    Q_OBJECT
public:
    ~MereStickyThemePicker();
    explicit MereStickyThemePicker(QWidget *parent = 0);

private:
    void initUI();

signals:
    void themeSelected(MereStickyTheme *theme);

private:
    QPushButton *m_stickyTitleLeftMenu;
};

#endif // MERESTHEMEPICKER_H

#ifndef MERESTHEMEPICKER_H
#define MERESTHEMEPICKER_H

#include <QWidget>
#include <QDebug>

class Theme;

class ThemePicker : public QWidget
{
    Q_OBJECT
public:
    ~ThemePicker();
    explicit ThemePicker(QWidget *parent = 0);

private:
    void initUI();

signals:
    void themeSelected(const Theme &theme);

private:
};

#endif // MERESTHEMEPICKER_H

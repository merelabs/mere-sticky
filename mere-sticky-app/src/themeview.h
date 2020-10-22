#ifndef THEMEVIEW_H
#define THEMEVIEW_H

#include "mere/widgets/editablelabel.h"
#include <QPushButton>

class Theme;
class EditableLabel;

class ThemeView : public QWidget
{
    Q_OBJECT
public:
    ~ThemeView();
    explicit ThemeView(Theme &theme, QWidget *parent = nullptr);

private:
    void initUI();

signals:
    void removed(const Theme &theme);

private slots:
    bool removeTheme();

private:
    Theme &m_theme;

    QPushButton *m_backgroud;
    Mere::Widgets::EditableLabel *m_name;
};

#endif // THEMEVIEW_H

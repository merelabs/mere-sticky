#ifndef THEMELISTWIDGET_H
#define THEMELISTWIDGET_H

#include "mere/widgets/resizeablewin.h"
#include <QDebug>

class Theme;
class ThemeListWidget : public Mere::Widgets::ResizeableWin
{
    Q_OBJECT
public:
    ~ThemeListWidget();
    explicit ThemeListWidget(QWidget *parent = nullptr);
    void init();

private:
    void initHeaderUI();
    void initContentUI();
    void initFooterUI();

    void updateContentUI();
signals:

private slots:
    bool addTheme();
    bool removeTheme(const Theme &theme);

private:
    QList<Theme *> m_themes;

    QWidget *m_contentWidget;
};

#endif // THEMELISTWIDGET_H

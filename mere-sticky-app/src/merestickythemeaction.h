#ifndef MERESTICKYTHEMEACTION_H
#define MERESTICKYTHEMEACTION_H

#include <QDebug>
#include <QWidget>
#include <QWidgetAction>

class MereStickyTheme;

class MereStickyThemeAction : public QWidgetAction
{
    Q_OBJECT
public:
    ~MereStickyThemeAction();
    explicit MereStickyThemeAction(QWidget *parent = nullptr);
    explicit MereStickyThemeAction(MereStickyTheme *theme, QWidget *parent = nullptr);

    MereStickyTheme* theme() const;

signals:
    void triggered(MereStickyTheme *theme);

protected:
    bool eventFilter(QObject *object, QEvent *event) override;
//    QWidget *createWidget(QWidget *parent);
//    void deleteWidget(QWidget *widget);

public slots:
private:
    QWidget *m_widget;
    MereStickyTheme *m_theme;
};

#endif // MERESTICKYTHEMEACTION_H

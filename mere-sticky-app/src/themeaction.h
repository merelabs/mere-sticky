#ifndef MERESTICKYTHEMEACTION_H
#define MERESTICKYTHEMEACTION_H

#include <QDebug>
#include <QWidget>
#include <QWidgetAction>

class Theme;

class ThemeAction : public QWidgetAction
{
    Q_OBJECT
public:
    ~ThemeAction();
    explicit ThemeAction(const Theme &theme, QWidget *parent = nullptr);

    const Theme& theme() const;

signals:
    void triggered(const Theme &theme);

protected:
    bool eventFilter(QObject *object, QEvent *event) override;
//    QWidget *createWidget(QWidget *parent);
//    void deleteWidget(QWidget *widget);

public slots:
private:
    QWidget *m_widget;
    const Theme &m_theme;
};

#endif // MERESTICKYTHEMEACTION_H

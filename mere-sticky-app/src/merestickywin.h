#ifndef MERESTICKYWIN_H
#define MERESTICKYWIN_H

#include "mere/widgets/merewidgetresizer.h"

#include <QWidget>

class MereStickyTheme;
class MereStickyTitleWidget;
class MereStickyNoteWidget;

class MereStickyWin : public QWidget, public MereResizeableWidget
{
    Q_OBJECT
public:
    explicit MereStickyWin(QWidget *parent = nullptr);

    void setResizer(MereWidgetResizer *resizer);
    void adjustSize(const QSize &size);

    void init();

protected:
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void initUI();
    void initHeaderUI();
    void initContentUI();
    void initFooterUI();

signals:

public slots:
private slots:
    void applyTheme(MereStickyTheme *theme);

private:
    QPoint m_point;
    bool m_lock;
    MereWidgetResizer *m_resizer;

    MereStickyTitleWidget *stickyTitleWidget;
    MereStickyNoteWidget *stickyNoteWidget;
};

#endif // MERESTICKYWIN_H

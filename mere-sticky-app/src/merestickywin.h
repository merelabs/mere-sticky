#ifndef MERESTICKYWIN_H
#define MERESTICKYWIN_H

#include "mere/widgets/mereresizeablewin.h"

#include <QWidget>
#include <QDebug>

class MereStickyTheme;
class MereStickyWinHeader;
class MereStickyNoteWidget;

class MereStickyWin : public MereResizeableWin
{
    Q_OBJECT
public:
    explicit MereStickyWin(QWidget *parent = nullptr);
    void init();

private:
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

    MereStickyWinHeader *stickyTitleWidget;
    MereStickyNoteWidget *stickyNoteWidget;
};

#endif // MERESTICKYWIN_H

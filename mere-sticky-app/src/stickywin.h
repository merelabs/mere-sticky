#ifndef MERESTICKYWIN_H
#define MERESTICKYWIN_H

#include "mere/widgets/mereresizeablewin.h"

class WinHeader;
class NoteWidget;
class Theme;
class Chirkut;

class StickyWin : public MereResizeableWin
{
    Q_OBJECT
public:
    ~StickyWin();
    explicit StickyWin(Chirkut &chirkut, QWidget *parent = nullptr);

    void init();

private:
    void initHeaderUI();
    void initContentUI();
    void initFooterUI();

    void resize();

signals:

private slots:
    void applyTheme(const Theme &theme);
    void close();

private:
    Chirkut &m_chirkut;

    WinHeader *m_titleWidget;
    NoteWidget *m_noteWidget;
};

#endif // MERESTICKYWIN_H

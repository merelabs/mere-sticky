#ifndef MERESTICKYWIN_H
#define MERESTICKYWIN_H

#include "mere/widgets/resizeablewin.h"

class SearchView;
class StickyWinHeader;
class NoteEditor;
class Theme;
class Issue;

class StickyWin : public Mere::Widgets::ResizeableWin
{
    Q_OBJECT
public:
    ~StickyWin();
    explicit StickyWin(Issue &issue, QWidget *parent = nullptr);

    void init();

    void keyPressEvent(QKeyEvent *e) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    void initHeaderUI() override;
    void initContentUI() override;
    void initFooterUI() override;

    void resize();

signals:

private slots:
    void applyTheme(const Theme &theme);
    void close();

private:
    Issue &m_chirkut;

    StickyWinHeader *m_titleWidget;
    NoteEditor *m_noteEditor;

    SearchView *m_searchView;
};

#endif // MERESTICKYWIN_H

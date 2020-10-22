#ifndef STICKYWINWRAPER_H
#define STICKYWINWRAPER_H

#include "mere/widgets/resizeablewin.h"

class Issue;
class StickyWinWrapper : public QWidget
{
    Q_OBJECT
public:
    ~StickyWinWrapper();
    explicit StickyWinWrapper(Issue &issue, QWidget *parent = nullptr);

    void init();

protected:
    void initHeaderUI(){};
    void initContentUI(){};
    void initFooterUI(){};

private:
    void initUI();

signals:

private:
    Issue &m_issue;
};

#endif // STICKYWINWRAPER_H

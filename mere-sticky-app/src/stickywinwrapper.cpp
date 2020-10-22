#include "stickywinwrapper.h"
#include "stickywin.h"

#include "mere/sticky/domain/model/issue.h"

StickyWinWrapper::~StickyWinWrapper()
{

}

StickyWinWrapper::StickyWinWrapper(Issue &issue, QWidget *parent)
    : QWidget(parent),
      m_issue(issue)
{
    setObjectName(QString::fromUtf8("MereWin"));
    setWindowFlags(Qt::FramelessWindowHint);
    initUI();
}

void StickyWinWrapper::init()
{

}

void StickyWinWrapper::initUI()
{
    StickyWin *win = new StickyWin(m_issue, this);
    win->init();
    win->show();
}


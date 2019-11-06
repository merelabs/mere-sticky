#include "merestickyapp.h"
#include "merestickywin.h"

#include <QFile>

MereStickyApp::~MereStickyApp()
{

}

MereStickyApp::MereStickyApp(int &argc, char **argv)
    : MereDefaultApp(argc, argv),
      m_win(new MereStickyWin)
{
    setObjectName("MereStickyApp");
    setAppCode(Mere::Sticky::AppCode);
    setApplicationName(Mere::Sticky::AppName);
    setApplicationVersion(Mere::Sticky::AppVersion);
}

void MereStickyApp::init()
{
    MereDefaultApp::init();

    m_win->init();
}

void MereStickyApp::start()
{
    m_win->show();
}

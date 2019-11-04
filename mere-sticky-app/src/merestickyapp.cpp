#include "merestickyapp.h"
#include "merestickywin.h"

#include <QFile>

MereStickyApp::~MereStickyApp()
{

}

MereStickyApp::MereStickyApp(int &argc, char **argv)
    : QApplication(argc, argv),
      m_win(new MereStickyWin)
{
    QFile File(":/sticky/sticky.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    qApp->setStyleSheet(StyleSheet);
}

void MereStickyApp::init()
{
    m_win->init();
}

void MereStickyApp::start()
{
    m_win->show();
}

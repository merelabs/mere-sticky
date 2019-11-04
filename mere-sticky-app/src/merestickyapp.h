#ifndef MEREBOARDAPP_H
#define MEREBOARDAPP_H

#include <QApplication>

class MereStickyWin;
class MereStickyApp : public QApplication
{
public:
    ~MereStickyApp();
    MereStickyApp(int &argc, char **argv);

    void init();
    void start();

private:
    MereStickyWin *m_win;
};

#endif // MEREBOARDAPP_H

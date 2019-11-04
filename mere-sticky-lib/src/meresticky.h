#ifndef MEREBOARD_H
#define MEREBOARD_H

#include "merestickyglobal.h"

#include <QObject>
#include <QProcess>

//class MereStickyWidget;

class MERE_STICKY_LIBSPEC MereSticky : public QObject
{
    Q_OBJECT
public:
    ~MereSticky();
    explicit MereSticky(QObject *parent = nullptr);

    void init();
    void show();

private:
//    MereStickyWidget *m_widget;
};

#endif // MEREBOARD_H

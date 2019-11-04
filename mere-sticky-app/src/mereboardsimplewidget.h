#ifndef MEREBOARDSIMPLE_H
#define MEREBOARDSIMPLE_H

#include <QWidget>

namespace Ui {
class MereBoardSimple;
}

class MereBoardSimple : public QWidget
{
    Q_OBJECT

public:
    explicit MereBoardSimple(QWidget *parent = 0);
    ~MereBoardSimple();

private:
    Ui::MereBoardSimple *ui;
};

#endif // MEREBOARDSIMPLE_H

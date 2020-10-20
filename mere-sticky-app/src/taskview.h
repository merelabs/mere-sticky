#ifndef TASKVIEW_H
#define TASKVIEW_H

//#include <QWidget>
#include <QPushButton>

class MereEditableLabel;

class TaskView : public QWidget
{
    Q_OBJECT
public:
    explicit TaskView(QWidget *parent = nullptr);

private:
    void initUI();
signals:

private:
    QPushButton *m_mark;
    MereEditableLabel *m_title;
};

#endif // TASKVIEW_H

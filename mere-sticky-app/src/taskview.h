#ifndef TASKVIEW_H
#define TASKVIEW_H

#include "mere/widgets/editablelabel.h"

#include <QPushButton>

class Task;
class EditableLabel;

class TaskView : public QWidget
{
    Q_OBJECT
public:
    explicit TaskView(Task &task, QWidget *parent = nullptr);

private:
    void initUI();
    void updateMarkUI();

signals:
    void removed(const Task &task);

private slots:
    bool updateTaskMark();
    bool updateTaskTitle();

    bool removeTask();

private:
    QPushButton *m_mark;
    Mere::Widgets::EditableLabel *m_title;

    Task &m_task;
};

#endif // TASKVIEW_H

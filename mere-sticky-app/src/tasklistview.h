#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QDebug>
#include <QWidget>

class Task;
class Issue;

class TaskListView : public QWidget
{
    Q_OBJECT
public:
    ~TaskListView();
    explicit TaskListView(Issue &chirkut, QWidget *parent = nullptr);

private:
    void init();
    void initUI();

    void initHeaderUI();
    void initContentUI();
    void updateContentUI();

signals:

private slots:
    bool addTask();
    bool removeTask(const Task &task);

    void toggledView();

private:
    Issue &m_issue;

    QWidget *m_contentWidget;
};

#endif // CHECKLIST_H

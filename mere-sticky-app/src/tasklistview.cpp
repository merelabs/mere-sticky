#include "tasklistview.h"
#include "taskview.h"

#include "mere/sticky/domain/model/task.h"
#include "mere/sticky/domain/model/issue.h"
#include "mere/sticky/service/issueservice.h"

#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QInputDialog>
#include <QFuture>
#include <QtConcurrent>
#include <QHBoxLayout>

TaskListView::~TaskListView()
{

}

TaskListView::TaskListView(Issue &chirkut, QWidget *parent)
    : QWidget(parent),
      m_issue(chirkut)
{
    QPalette p = palette();
    p.setColor( QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette( p );

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 0);
    layout->setSpacing(5);

    setLayout(layout);

    init();
    initUI();
}

void TaskListView::init()
{
    QFuture<QList<Task *> > future = QtConcurrent::run([=]{
        IssueService service;

        QList<Task *> tasks = service.tasks(m_issue);
        return tasks;
    });

    future.waitForFinished();

    QList<Task *> tasks = future.result();
    qDebug() << "Number of tasks found:" << tasks.size();
    m_issue.setTasks(tasks);
}

void TaskListView::initUI()
{
    initHeaderUI();
    initContentUI();
}

void TaskListView::initHeaderUI()
{
    QWidget *header = new QWidget();
    header->setMaximumHeight(28);
    layout()->addWidget(header);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(3, 3, 7, 3);
    layout->setSpacing(5);
    layout->setAlignment(Qt::AlignLeft);

    header->setLayout(layout);

    QPushButton *btnTitle = new QPushButton;
    btnTitle->setIcon(QIcon(":/sticky/checklist.png"));
    btnTitle->setText(tr("Checklist"));
    btnTitle->setFlat(true);

    layout->addWidget(btnTitle);

    QSpacerItem *spacer= new QSpacerItem (20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->addItem(spacer);

    QPushButton *button = new QPushButton();
    button->setText("+");
    button->setFlat(true);
    button->setMaximumSize(QSize(16, 16));

    layout->addWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(addTask()));
    connect(btnTitle, SIGNAL(clicked()), this, SLOT(toggledView()));
}

void TaskListView::initContentUI()
{
    m_contentWidget = new QWidget();

    layout()->addWidget(m_contentWidget);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(5);
    m_contentWidget->setLayout(layout);

    updateContentUI();

    m_contentWidget->setMaximumHeight(0);
}

void TaskListView::updateContentUI()
{    
    // clear
    qDeleteAll(m_contentWidget->findChildren<TaskView *>());

    QList<Task *> tasks = m_issue.tasks();
    QListIterator<Task *> it(tasks);
    while (it.hasNext())
    {
        Task *task = it.next();
        TaskView *taskView = new TaskView(*task);
        connect(taskView, SIGNAL(removed(const Task &)), this, SLOT(removeTask(const Task &)));
        m_contentWidget->layout()->addWidget(taskView);
    }
}

bool TaskListView::addTask()
{
    bool ok;

    QString text = QInputDialog::getText(this, "",
                                       tr("Enter the item to be checked:"), QLineEdit::Normal,
                                       "", &ok, Qt::CustomizeWindowHint);
    if (!ok || text.isEmpty()) return false;

    Task *task = new Task();
    task->setMark(Task::Mark::Open);
    task->setTitle(text);

    m_issue.addTask(task);

    IssueService service;
    QUuid uuid = service.save(m_issue);
    if (!uuid.isNull())
    {
        updateContentUI();
    }

    return true;
}

bool TaskListView::removeTask(const Task &task)
{
    bool ok = false;

    QList<Task *> tasks = m_issue.tasks();
    QMutableListIterator<Task *> it(tasks);
    while (it.hasNext())
    {
        Task *_task = it.next();
        if (!_task) continue;

        if (_task->uuid() == task.uuid())
        {
            it.remove();
            ok = true;
            break;
        }
    }

    return ok;
}

void TaskListView::toggledView()
{
    static bool hidden = true;

    int size   = m_issue.tasks().size();
    if (size == 0) return;

    int height = size * 36 + (size - 1) * m_contentWidget->layout()->spacing();

    QPropertyAnimation *animation = new QPropertyAnimation(m_contentWidget, "maximumHeight");
    animation->setDuration(size * 30);

    if (hidden)
    {
        animation->setStartValue(0);
        animation->setEndValue(height);
    }
    else
    {
        animation->setStartValue(height);
        animation->setEndValue(0);
    }
    animation->start();

    connect(animation, &QPropertyAnimation::finished, [animation](){animation->deleteLater();});

    hidden = !hidden;
}

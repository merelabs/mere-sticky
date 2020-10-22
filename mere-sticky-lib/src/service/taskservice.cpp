#include "taskservice.h"
#include "../domain/model/task.h"
#include "../domain/store/taskstore.h"

TaskService::TaskService(QObject *parent)
    : BaseService(parent)
{

}

Task* TaskService::fetch(QUuid uuid)
{
    return BaseService::fetch<TaskStore, Task>(uuid);
}

QList<Task *> TaskService::list()
{
    return BaseService::list<TaskStore, Task>();
}

QUuid TaskService::save(Task &task)
{
    QUuid uuid = task.uuid();
    if (uuid.isNull())
        return create(task);

    return update(task);
}

QUuid TaskService::create(Task &task)
{
    TaskStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice task; check if it is created!";
        return 0;
    }

    task.setCreatedAt(QDateTime::currentDateTime());
    task.setUpdatedAt(QDateTime::currentDateTime());

    err = store.create(task);
    if (err)
    {
        qDebug() << "Failed to create task!";
        return 0;
    }

    emit created(task);
    emit created(task.uuid());

    qDebug() << "Task created:" << task.uuid();

    return task.uuid();
}

QUuid TaskService::update(Task &task)
{
    TaskStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice task; check if it is created!";
        return 0;
    }

    task.setUpdatedAt(QDateTime::currentDateTime());

    err = store.update(task);
    if (err)
    {
        qDebug() << "Failed to update task!";
        return 0;
    }

    emit updated(task);
    emit updated(task.uuid());

    qDebug() << "Task updated:" << task.uuid();

    return task.uuid();
}

bool TaskService::remove(Task &task)
{
    TaskStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice task; check if it is created!";
        return false;
    }

    err = store.remove(task);
    if (err)
    {
        qDebug() << "Failed to remove task!";
        return false;
    }

    emit removed(task);
    emit removed(task.uuid());

    qDebug() << "Task removed:" << task.uuid();

    return true;
}

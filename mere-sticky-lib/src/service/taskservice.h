#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include "baseservice.h"

class Task;

class MERE_STICKY_LIBSPEC TaskService : public BaseService
{
    Q_OBJECT
public:
    explicit TaskService(QObject *parent = nullptr);

    Task* fetch(QUuid uuid);
    QList<Task *> list();

    QUuid save(Task &task);
    QUuid create(Task &task);
    QUuid update(Task &task);
    bool remove(Task &task);

signals:
    void ready();

    void created(QUuid uid);
    void created(Task &task);

    void updated(QUuid uid);
    void updated(Task &task);

    void removed(QUuid uid);
    void removed(Task &task);
};

#endif // TASKSERVICE_H

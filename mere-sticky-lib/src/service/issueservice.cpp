#include "issueservice.h"
#include "taskservice.h"

#include "../domain/model/issue.h"
#include "../domain/model/task.h"
#include "../domain/store/issuestore.h"

IssueService::IssueService(QObject *parent)
    : BaseService(parent)
{

}

Issue* IssueService::fetch(QUuid uuid)
{
    return BaseService::fetch<IssueStore, Issue>(uuid);
}

QList<Issue *> IssueService::list()
{
    return BaseService::list<IssueStore, Issue>();
}

QUuid IssueService::save(Issue &issue)
{
    QUuid uuid = issue.uuid();
    if (uuid.isNull())
        return create(issue);

    return update(issue);
}

QUuid IssueService::create(Issue &issue)
{
    IssueStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice issue; check if it is created!";
        return 0;
    }

    issue.setCreatedAt(QDateTime::currentDateTime());

    err = store.create(issue);
    if (err)
    {
        qDebug() << "Failed to create issue!";
        return 0;
    }

    emit created(issue);
    emit created(issue.uuid());

    qDebug() << "Issue created:" << issue.uuid();

    return issue.uuid();
}

QUuid IssueService::update(Issue &issue)
{
    IssueStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice issue; check if it is created!";
        return 0;
    }

    issue.setUpdatedAt(QDateTime::currentDateTime());
    err = store.update(issue);
    if (err)
    {
        qDebug() << "Failed to update issue!";
        return 0;
    }

    bool linked = false;
    TaskService taskService;

    QList<Task *> tasks = issue.tasks();
    qDebug() << "Number of tasks:" << tasks.size();

    QListIterator<Task *> it(tasks);
    while (it.hasNext())
    {
        Task *task = it.next();
        if (!task) continue;

        task->addLink("part-of", issue);

        QUuid uuid = taskService.save(*task);
        if (!uuid.isNull())
        {
            issue.addLink("consist-of", *task);
            linked = true;
        }
    }

    if (linked)
    {
        err = store.update(issue);
        if (err)
        {
            qDebug() << "Failed to update issue while linking with tasks!";
            return 0;
        }
    }

    emit updated(issue);
    emit updated(issue.uuid());

    qDebug() << "Issue updated:" << issue.uuid();

    return issue.uuid();
}

QUuid IssueService::remove(Issue &issue)
{
    QUuid uuid;

    IssueStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice issue; check if it is created!";
        return 0;
    }

    err = store.remove(issue);
    if (err)
    {
        qDebug() << "Failed to remove issue!";
        return 0;
    }

    emit removed(issue);
    emit removed(issue.uuid());

    qDebug() << "Issue removed:" << issue.uuid();

    return uuid;
}

QList<Task *> IssueService::tasks(Issue &issue)
{
    QList<Task *> tasks;

    TaskService service;

    QList<Mere::Store::Link> links = issue.links();
    QListIterator<Mere::Store::Link> lit(links);
    while (lit.hasNext())
    {
        Mere::Store::Link link = lit.next();
        if (link.name().compare("consist-of") != 0)
            continue;

        QList<Mere::Store::UnitRef> units = link.units();
        QListIterator<Mere::Store::UnitRef> it(units);
        while (it.hasNext())
        {
            Mere::Store::UnitRef ref = it.next();
            if (ref.type().compare("task") != 0)
                continue;

            Task *task = service.fetch(ref.uuid());
            if (task)
                tasks.append(task);
        }
    }

    // Sort the list based on 'order'
    std::sort(tasks.begin(), tasks.end(), [](Task *a, Task *b) {
            return a->order() < b->order();
    });

    return tasks;
}

QList<Issue *> IssueService::find(const QString &what)
{
    QList<Issue *> issues;

    IssueStore store;
    int err = store.open();
    if (err) return issues;

    QList<Mere::Store::Pair> pairs = store.query("title", what);
    QListIterator<Mere::Store::Pair> it(pairs);
    while (it.hasNext())
    {
        Mere::Store::Pair pair = it.next();

        Mere::Store::UnitRef ref = (pair.value()).value<Mere::Store::UnitRef>();

        Issue *issue = store.fetch<Issue>(ref.uuid());
        if (!issue) continue;
        issues.append(issue);
    }

    return issues;
}

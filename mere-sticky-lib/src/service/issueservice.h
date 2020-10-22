#ifndef ISSUESERVICE_H
#define ISSUESERVICE_H

#include "baseservice.h"

class Task;
class Issue;
class MERE_STICKY_LIBSPEC IssueService : public BaseService
{
    Q_OBJECT
public:
    explicit IssueService(QObject *parent = nullptr);

    Issue* fetch(QUuid uuid);
    QList<Issue *> list();

    QUuid save(Issue &issue);
    QUuid create(Issue &issue);
    QUuid update(Issue &issue);
    QUuid remove(Issue &issue);

    QList<Task *> tasks(Issue &issue);

    QList<Issue *> find(const QString &what);

signals:
    void ready();

    void created(QUuid uid);
    void created(Issue &issue);

    void updated(QUuid uid);
    void updated(Issue &issue);

    void removed(QUuid uid);
    void removed(Issue &issue);
};

#endif // ISSUESERVICE_H

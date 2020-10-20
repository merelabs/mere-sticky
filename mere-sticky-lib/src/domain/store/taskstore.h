#ifndef CHECKSTORE_H
#define CHECKSTORE_H

#include "basestore.h"

class TaskStore : public BaseStore
{
    Q_OBJECT
public:
    virtual ~TaskStore();
    explicit TaskStore(QObject *parent = nullptr);

signals:

};

#endif // CHECKSTORE_H

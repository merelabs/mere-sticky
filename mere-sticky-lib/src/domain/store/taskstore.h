#ifndef CHECKSTORE_H
#define CHECKSTORE_H

#include "basestore.h"

class MERE_STICKY_LIBSPEC TaskStore : public BaseStore
{
    Q_OBJECT
public:
    virtual ~TaskStore();
    explicit TaskStore(QObject *parent = nullptr);

signals:

};

#endif // CHECKSTORE_H

#ifndef CHIRKUTSTORE_H
#define CHIRKUTSTORE_H

#include "basestore.h"

class ChirkutStore : public BaseStore
{
    Q_OBJECT
public:
    virtual ~ChirkutStore();
    explicit ChirkutStore(QObject *parent = nullptr);

signals:

};

#endif // CHIRKUTSTORE_H

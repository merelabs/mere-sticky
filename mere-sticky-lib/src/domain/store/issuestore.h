#ifndef CHIRKUTSTORE_H
#define CHIRKUTSTORE_H

#include "basestore.h"

class MERE_STICKY_LIBSPEC IssueStore : public BaseStore
{
    Q_OBJECT
public:
    virtual ~IssueStore();
    explicit IssueStore(QObject *parent = nullptr);

signals:

};

#endif // CHIRKUTSTORE_H

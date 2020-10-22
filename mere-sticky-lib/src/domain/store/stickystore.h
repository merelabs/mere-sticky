#ifndef NOTESTORE_H
#define NOTESTORE_H

#include "basestore.h"

class MERE_STICKY_LIBSPEC StickyStore : public BaseStore
{
    Q_OBJECT
public:
    ~StickyStore();
    explicit StickyStore(QObject *parent = nullptr);

signals:

};

#endif // NOTESTORE_H

#ifndef THEMESTORE_H
#define THEMESTORE_H

#include "basestore.h"

class MERE_STICKY_LIBSPEC ThemeStore : public BaseStore
{
    Q_OBJECT
public:
    ~ThemeStore();
    explicit ThemeStore(QObject *parent = nullptr);

signals:

};

#endif // THEMESTORE_H

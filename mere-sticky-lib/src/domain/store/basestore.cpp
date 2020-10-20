#include "basestore.h"

BaseStore::BaseStore(QObject *parent)
    : UnitStore("chirkut", parent)
{
}

BaseStore::BaseStore(const QString &slice, QObject *parent)
    : UnitStore("chirkut", slice, parent)
{
}

QString BaseStore::path() const
{
    return "/home/iklash/.mere/sticky/store";
}


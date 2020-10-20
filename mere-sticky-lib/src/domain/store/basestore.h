#ifndef BASESTORE_H
#define BASESTORE_H

#include "mere/store/store/unitstore.h"

class BaseStore : public Mere::Store::UnitStore
{
    Q_OBJECT
public:
    explicit BaseStore(QObject *parent = nullptr);
    explicit BaseStore(const QString &slice, QObject *parent = nullptr);

    QString path() const override;

    template <typename T>
    T* fetch(QUuid uuid)
    {
        if (uuid.isNull())
            return nullptr;

        T *t = new T();
        t->setUuid(uuid);

        int err = UnitStore::fetch(*t, *t);
        if (err)
        {
            delete t;
            t = nullptr;
        }

        return t;
    }

    template <typename T>
    QList<T *> list()
    {
        QList<T *>  Ts;

        QVariant list = UnitStore::list(0);
        if (!list.isValid()) return Ts;

        QList<Mere::Store::Unit *> units = list.value<QList<Mere::Store::Unit*>>();
        QListIterator<Mere::Store::Unit *> it(units);
        while (it.hasNext())
        {
            Mere::Store::Unit *unit = it.next();
            if(!unit) continue;

            T *t = new T();
            t->setPath(unit->path());
            t->setType(unit->type());
            t->setUuid(unit->uuid());
            t->setAttributes(unit->attributes());
            t->setLinks(unit->links());
            Ts.append(t);

            delete unit;
        }

        return  Ts;
    }
};

#endif // BASESTORE_H

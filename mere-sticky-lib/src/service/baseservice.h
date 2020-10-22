#ifndef BASESERVICE_H
#define BASESERVICE_H

#include "../stickyglobal.h"

#include <QUuid>
#include <QObject>

class MERE_STICKY_LIBSPEC BaseService : public QObject
{
    Q_OBJECT
public:
    virtual ~BaseService();
    explicit BaseService(QObject *parent = nullptr);

    template <typename S, typename T>
    T* fetch(QUuid uuid)
    {
        if (uuid.isNull())
            return nullptr;

        S store;
        int err = store.open();
        if (err) return 0;

        return store.template fetch<T>(uuid);
    }

    template <typename S, typename T>
    QList<T *> list()
    {
        QList<T *>  Ts;

        S store;

        int err = store.open();
        if (err) return Ts;

        Ts = store.template list<T>();

        return  Ts;
    }
};

#endif // BASESERVICE_H

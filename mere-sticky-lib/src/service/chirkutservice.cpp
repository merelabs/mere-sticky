#include "chirkutservice.h"
#include "../domain/model/chirkut.h"
#include "../domain/store/chirkutstore.h"

ChirkutService::ChirkutService(QObject *parent)
    : BaseService(parent)
{

}

Chirkut* ChirkutService::fetch(QUuid uuid)
{
    return BaseService::fetch<ChirkutStore, Chirkut>(uuid);
}

QList<Chirkut *> ChirkutService::list()
{
    return BaseService::list<ChirkutStore, Chirkut>();
}

QUuid ChirkutService::save(Chirkut &chirkut)
{
    QUuid uuid = chirkut.uuid();
    if (uuid.isNull())
        return create(chirkut);

    return update(chirkut);
}

QUuid ChirkutService::create(Chirkut &chirkut)
{
    ChirkutStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice chirkut; check if it is created!";
        return 0;
    }

    err = store.create(chirkut);
    if (err)
    {
        qDebug() << "Failed to create chirkut!";
        return 0;
    }

    emit created(chirkut);
    emit created(chirkut.uuid());

    qDebug() << "Chirkut created:" << chirkut.uuid();

    return chirkut.uuid();
}

QUuid ChirkutService::update(Chirkut &chirkut)
{
    ChirkutStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice chirkut; check if it is created!";
        return 0;
    }

    err = store.update(chirkut);
    if (err)
    {
        qDebug() << "Failed to update chirkut!";
        return 0;
    }

    emit updated(chirkut);
    emit updated(chirkut.uuid());

    qDebug() << "Chirkut updated:" << chirkut.uuid();

    return chirkut.uuid();
}

QUuid ChirkutService::remove(Chirkut &chirkut)
{
    QUuid uuid;

    ChirkutStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice chirkut; check if it is created!";
        return 0;
    }

    err = store.remove(chirkut);
    if (err)
    {
        qDebug() << "Failed to remove chirkut!";
        return 0;
    }

    emit removed(chirkut);
    emit removed(chirkut.uuid());

    qDebug() << "Chirkut removed:" << chirkut.uuid();

    return uuid;
}

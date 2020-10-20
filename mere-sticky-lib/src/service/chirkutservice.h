#ifndef NOTESERVICE_H
#define NOTESERVICE_H

#include "baseservice.h"

class Chirkut;
class ChirkutService : public BaseService
{
    Q_OBJECT
public:
    explicit ChirkutService(QObject *parent = nullptr);

    Chirkut* fetch(QUuid uuid);
    QList<Chirkut *> list();

    QUuid save(Chirkut &chirkut);
    QUuid create(Chirkut &chirkut);
    QUuid update(Chirkut &chirkut);
    QUuid remove(Chirkut &chirkut);

signals:
    void ready();

    void created(QUuid uid);
    void created(Chirkut &chirkut);

    void updated(QUuid uid);
    void updated(Chirkut &chirkut);

    void removed(QUuid uid);
    void removed(Chirkut &chirkut);

};

#endif // NOTESERVICE_H

#ifndef CATEGORYSERVICE_H
#define CATEGORYSERVICE_H

#include "baseservice.h"

class Category;
class MERE_STICKY_LIBSPEC CategoryService : public BaseService
{
    Q_OBJECT
public:
    explicit CategoryService(QObject *parent = nullptr);

    Category* fetch(QUuid uuid);
    QList<Category *> list();

    QUuid save(Category &category);
    QUuid create(Category &category);
    QUuid update(Category &category);
    QUuid remove(Category &category);

signals:
    void ready();

    void created(QUuid uid);
    void created(Category &category);

    void updated(QUuid uid);
    void updated(Category &category);

    void removed(QUuid uid);
    void removed(Category &category);
};

#endif // CATEGORYSERVICE_H

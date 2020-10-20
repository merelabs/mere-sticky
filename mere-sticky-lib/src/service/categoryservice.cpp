#include "categoryservice.h"
#include "../domain/model/category.h"
#include "../domain/store/stickystore.h"

CategoryService::CategoryService(QObject *parent)
    : BaseService(parent)
{

}

Category* CategoryService::fetch(QUuid uuid)
{
    return BaseService::fetch<StickyStore, Category>(uuid);
}

QList<Category *> CategoryService::list()
{
    return BaseService::list<StickyStore, Category>();
}

QUuid CategoryService::save(Category &category)
{
    QUuid uuid = category.uuid();
    if (uuid.isNull())
        return create(category);

    return update(category);
}

QUuid CategoryService::create(Category &category)
{
    StickyStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice chirkut; check if it is created!";
        return 0;
    }

    err = store.create(category);
    if (err)
    {
        qDebug() << "Failed to create category!";
        return 0;
    }

    emit created(category);
    emit created(category.uuid());

    qDebug() << "Category created:" << category.uuid();

    return category.uuid();
}

QUuid CategoryService::update(Category &category)
{
    StickyStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice chirkut; check if it is created!";
        return 0;
    }

    err = store.update(category);
    if (err)
    {
        qDebug() << "Failed to update category!";
        return 0;
    }

    emit updated(category);
    emit updated(category.uuid());

    qDebug() << "Category updated:" << category.uuid();

    return category.uuid();
}

QUuid CategoryService::remove(Category &category)
{
    QUuid uuid;

    StickyStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice chirkut; check if it is created!";
        return 0;
    }

    err = store.remove(category);
    if (err)
    {
        qDebug() << "Failed to remove category!";
        return 0;
    }

    emit removed(category);
    emit removed(category.uuid());

    qDebug() << "Category removed:" << category.uuid();

    return uuid;
}

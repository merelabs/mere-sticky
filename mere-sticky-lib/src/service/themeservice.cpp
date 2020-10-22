#include "themeservice.h"
#include "../domain/model/theme.h"
#include "../domain/store/themestore.h"

ThemeService::ThemeService(QObject *parent)
    : BaseService(parent)
{

}

Theme* ThemeService::fetch(QUuid uuid)
{
    return BaseService::fetch<ThemeStore, Theme>(uuid);
}

QList<Theme *> ThemeService::list()
{
    return BaseService::list<ThemeStore, Theme>();
}

QUuid ThemeService::save(Theme &theme)
{
    QUuid uuid = theme.uuid();
    if (uuid.isNull())
        return create(theme);

    return update(theme);
}

QUuid ThemeService::create(Theme &theme)
{
    ThemeStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice theme; check if it is created!";
        return 0;
    }

    theme.setCreatedAt(QDateTime::currentDateTime());

    err = store.create(theme);
    if (err)
    {
        qDebug() << "Failed to create theme!";
        return 0;
    }

    emit created(theme);
    emit created(theme.uuid());

    qDebug() << "Theme created:" << theme.uuid();

    return theme.uuid();
}

QUuid ThemeService::update(Theme &theme)
{
    ThemeStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice theme; check if it is created!";
        return 0;
    }

    theme.setUpdatedAt(QDateTime::currentDateTime());

    err = store.update(theme);
    if (err)
    {
        qDebug() << "Failed to update theme!";
        return 0;
    }

    emit updated(theme);
    emit updated(theme.uuid());

    qDebug() << "Theme updated:" << theme.uuid();

    return theme.uuid();
}

bool ThemeService::remove(Theme &theme)
{
    ThemeStore store;
    int err = store.open();
    if (err)
    {
        qDebug() << "Failed to open slice theme; check if it is created!";
        return false;
    }

    err = store.remove(theme);
    if (err)
    {
        qDebug() << "Failed to remove theme!";
        return false;
    }

    emit removed(theme);
    emit removed(theme.uuid());

    qDebug() << "Theme removed:" << theme.uuid();

    return true;
}

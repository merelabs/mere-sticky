#ifndef THEMESERVICE_H
#define THEMESERVICE_H

#include "baseservice.h"

class Theme;
class ThemeService : public BaseService
{
    Q_OBJECT
public:
    explicit ThemeService(QObject *parent = nullptr);

    Theme* fetch(QUuid uuid);
    QList<Theme *> list();

    QUuid save(Theme &theme);
    QUuid create(Theme &theme);
    QUuid update(Theme &theme);
    QUuid remove(Theme &theme);

signals:
    void ready();

    void created(QUuid uid);
    void created(Theme &theme);

    void updated(QUuid uid);
    void updated(Theme &theme);

    void removed(QUuid uid);
    void removed(Theme &theme);

};

#endif // THEMESERVICE_H

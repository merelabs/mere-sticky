#ifndef MERESTICKYCONFIG_H
#define MERESTICKYCONFIG_H

#include "merestickytheme.h"

#include <QObject>

class MereStickyConfig : public QObject
{
    Q_OBJECT
public:
    explicit MereStickyConfig(QObject *parent = nullptr);
    MereStickyTheme theme();

signals:

public slots:
};

#endif // MERESTICKYCONFIG_H

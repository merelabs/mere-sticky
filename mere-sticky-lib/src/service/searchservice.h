#ifndef SEARCHSERVICE_H
#define SEARCHSERVICE_H

#include "baseservice.h"

class Issue;

class MERE_STICKY_LIBSPEC SearchService : public BaseService
{
    Q_OBJECT
public:
    explicit SearchService(QObject *parent = nullptr);

     QList<Issue *> issues(const QString &what);

signals:

};

#endif // SEARCHSERVICE_H

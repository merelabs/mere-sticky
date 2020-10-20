#ifndef STICKYSERVICE_H
#define STICKYSERVICE_H

#include <QObject>

class StickyService : public QObject
{
    Q_OBJECT
public:
    explicit StickyService(QObject *parent = nullptr);

//    QList<Note *> notes();


signals:

};

#endif // STICKYSERVICE_H

#ifndef CHECK_H
#define CHECK_H

#include "../../stickyglobal.h"
#include "base.h"

class MERE_STICKY_LIBSPEC Task : public Base
{
public:
    ~Task();
    Task();

    enum Mark { Open = 0, Waiting, Prgress, Review, Complete };
    enum Priority {Low, Normal, Medium, High};

    QString title() const;
    void setTitle(const QString &title);

    Mark mark() const;
    void setMark(const Mark &mark);

    Priority priority() const;
    void setPriority(const Priority &priority);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

private:
    QString m_title;
    Mark m_mark;
    Priority m_priority;
};

#endif // CHECK_H

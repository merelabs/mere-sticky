#ifndef CHECK_H
#define CHECK_H

#include "base.h"

class MERE_STICKY_LIBSPEC Task : public Base
{
public:
    ~Task();
    Task();

    enum Mark { Open, Doing, Done };
    enum Priority {Low, Normal, Medium, High};

    QString title() const;
    void setTitle(const QString &title);

    Mark mark() const;
    void setMark(const Mark &mark);

    Priority priority() const;
    void setPriority(const Priority &priority);

    uint order() const;
    void setOrder(const uint &order);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

private:
    QString m_title;
    Mark m_mark;
    Priority m_priority;
    uint m_order;
};

#endif // CHECK_H

#ifndef CATEGORY_H
#define CATEGORY_H

#include "base.h"

class MERE_STICKY_LIBSPEC Category : public Base
{
public:
    ~Category();
    explicit Category();

    QString code() const;
    void setCode(const QString &code);

    QString name() const;
    void setName(const QString &name);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

private:
    QString m_code;
    QString m_name;
};

#endif // CATEGORY_H

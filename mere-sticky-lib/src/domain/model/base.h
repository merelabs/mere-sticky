#ifndef BASE_H
#define BASE_H

#include "../../stickyglobal.h"
#include "mere/store/unit.h"

#include <QDateTime>

class Base : public Mere::Store::Unit
{
public:
    explicit Base(const QString type);

    enum Status {Archive = 0, Live = 1};

    QDateTime createdAt() const;
    void setCreatedAt(const QDateTime &datetime);

    QDateTime updatedAt() const;
    void setUpdatedAt(const QDateTime &datetime);

    Status status() const;
    void setStatus(const Status &status);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

private:
    QDateTime m_createdAt;
    QDateTime m_updatedAt;
    Status m_status;
};

#endif // BASE_H

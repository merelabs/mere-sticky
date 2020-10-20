#include "base.h"

Base::Base(const QString type)
    : Unit(type)
{

}

QDateTime Base::createdAt() const
{
    return m_createdAt;
}

void Base::setCreatedAt(const QDateTime &datetime)
{
    m_createdAt = datetime;
}

QDateTime Base::updatedAt() const
{
    return m_updatedAt;
}

void Base::setUpdatedAt(const QDateTime &datetime)
{
    m_updatedAt = datetime;
}

Base::Status Base::status() const
{
    return m_status;
}

void Base::setStatus(const Status &status)
{
    m_status = status;
}

QMap<QString, QVariant> Base::attributes() const
{
    QMap<QString, QVariant> attrs;

    attrs.insert("created-at", createdAt().toString());
    attrs.insert("updated-at", updatedAt().toString());
    attrs.insert("status", status());

    return attrs;
}

void Base::setAttributes(QMap<QString, QVariant> attrs)
{
    QVariant value;

    if (attrs.contains("created-at"))
    {
        value = attrs["created-at"];
        this->setCreatedAt(QDateTime::fromString(value.toString()));
    }

    if (attrs.contains("updated-at"))
    {
        value = attrs["updated-at"];
        this->setUpdatedAt(QDateTime::fromString(value.toString()));
    }

    if (attrs.contains("status"))
    {
        value = attrs["status"];
        this->setStatus((Base::Status)value.toInt());
    }
}


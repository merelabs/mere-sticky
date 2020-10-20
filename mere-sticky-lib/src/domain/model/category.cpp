#include "category.h"

Category::~Category()
{

}

Category::Category()
    : Base("category")
{

}

QString Category::code() const
{
    return m_code;
}

void Category::setCode(const QString &code)
{
    m_code = code;
}

QString Category::name() const
{
    return m_name;
}

void Category::setName(const QString &name)
{
    m_name = name;
}

QMap<QString, QVariant> Category::attributes() const
{
    QMap<QString, QVariant> attrs;

    attrs.insert("code", code());
    attrs.insert("name", name());

    attrs.insert(Base::attributes());

    return attrs;
}

void Category::setAttributes(QMap<QString, QVariant> attrs)
{
    QVariant value;

    if (attrs.contains("code"))
    {
        value = attrs["code"];
        this->setCode(value.toString());
    }

    if (attrs.contains("name"))
    {
        value = attrs["name"];
        this->setName(value.toString());
    }

    Base::setAttributes(attrs);
}

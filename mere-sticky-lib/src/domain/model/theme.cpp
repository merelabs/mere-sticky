#include "theme.h"

Theme::~Theme()
{

}

Theme::Theme()
    : Base("theme")
{

}

QString Theme::code() const
{
    return m_code;
}

void Theme::setCode(const QString &code)
{
    m_code = code;
}

QString Theme::name() const
{
    return m_name;
}

void Theme::setName(const QString &name)
{
    m_name = name;
}

QString Theme::foreground() const
{
    return m_foreground;
}

void Theme::setForeground(const QString &color)
{
    m_foreground = color;
}

QString Theme::background() const
{
    return m_background;
}

void Theme::setBackground(const QString &color)
{
    m_background = color;
}

QMap<QString, QVariant> Theme::attributes() const
{
    QMap<QString, QVariant> attrs;

    attrs.insert("code", code());
    attrs.insert("name", name());
    attrs.insert("foreground", foreground());
    attrs.insert("background", background());

    attrs.insert(Base::attributes());

    return attrs;
}

void Theme::setAttributes(QMap<QString, QVariant> attrs)
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

    if (attrs.contains("foreground"))
    {
        value = attrs["foreground"];
        this->setForeground(value.toString());
    }

    if (attrs.contains("background"))
    {
        value = attrs["background"];
        this->setBackground(value.toString());
    }

    Base::setAttributes(attrs);
}

#include "chirkut.h"

Chirkut::~Chirkut()
{

}

Chirkut::Chirkut()
    : Base("chirkut")
{

}
QString Chirkut::title() const
{
    return m_title;
}

void Chirkut::setTitle(const QString &title)
{
    m_title = title;
}

QString Chirkut::note() const
{
    return m_note;
}

void Chirkut::setNote(const QString &note)
{
    m_note = note;
}

QMap<QString, QVariant> Chirkut::attributes() const
{
    QMap<QString, QVariant> attrs;

    attrs.insert("title", title());
    attrs.insert("note", note());

    attrs.insert(Base::attributes());

    return attrs;
}

void Chirkut::setAttributes(QMap<QString, QVariant> attrs)
{
    QVariant value;

    if (attrs.contains("title"))
    {
        value = attrs["title"];
        this->setTitle(value.toString());
    }

    if (attrs.contains("note"))
    {
        value = attrs["note"];
        this->setNote(value.toString());
    }

    Base::setAttributes(attrs);
}

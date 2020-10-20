#include "task.h"

Task::~Task()
{

}

Task::Task()
    : Base("task")
{

}

QString Task::title() const
{
    return m_title;
}

void Task::setTitle(const QString &title)
{
    m_title = title;
}

Task::Mark Task::mark() const
{
    return m_mark;
}

void Task::setMark(const Mark &mark)
{
    m_mark = mark;
}

Task::Priority Task::priority() const
{
    return m_priority;
}

void Task::setPriority(const Priority &priority)
{
    m_priority = priority;
}

QMap<QString, QVariant> Task::attributes() const
{
    QMap<QString, QVariant> attrs;

    attrs.insert("title", title());
    attrs.insert("mark", mark());
    attrs.insert("priority", priority());

    attrs.insert(Base::attributes());

    return attrs;
}

void Task::setAttributes(QMap<QString, QVariant> attrs)
{
    QVariant value;

    if (attrs.contains("title"))
    {
        value = attrs["title"];
        this->setTitle(value.toString());
    }

    if (attrs.contains("mark"))
    {
        value = attrs["mark"];
        this->setMark((Mark)value.toInt());
    }

    if (attrs.contains("priority"))
    {
        value = attrs["priority"];
        this->setPriority((Priority)value.toInt());
    }

    Base::setAttributes(attrs);
}

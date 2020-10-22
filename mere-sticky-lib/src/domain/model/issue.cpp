#include "issue.h"

Issue::~Issue()
{

}

Issue::Issue()
    : Base("issue")
{

}
QString Issue::title() const
{
    return m_title;
}

void Issue::setTitle(const QString &title)
{
    m_title = title;
}

QString Issue::note() const
{
    return m_note;
}

void Issue::setNote(const QString &note)
{
    m_note = note;
}

QList<Task *> Issue::tasks() const
{
    return m_tasks;
}

void Issue::addTask(Task *task)
{
    m_tasks.append(task);
}

void Issue::addTasks(QList<Task *> &tasks)
{
    m_tasks.append(tasks);
}

void Issue::setTasks(QList<Task *> &tasks)
{
    m_tasks.clear();
    m_tasks.append(tasks);
}

QMap<QString, QVariant> Issue::attributes() const
{
    QMap<QString, QVariant> attrs;

    attrs.insert("title", title());
    attrs.insert("note", note());

    attrs.insert(Base::attributes());

    return attrs;
}

void Issue::setAttributes(QMap<QString, QVariant> attrs)
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

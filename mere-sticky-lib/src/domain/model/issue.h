#ifndef NOTE_H
#define NOTE_H

#include "base.h"

class Task;

class MERE_STICKY_LIBSPEC Issue : public Base
{
public:
    ~Issue();
    explicit Issue();

    QString title() const;
    void setTitle(const QString &title);

    QString note() const;
    void setNote(const QString &note);

    QList<Task *> tasks() const;
    void addTask(Task *task);
    void addTasks(QList<Task *> &tasks);
    void setTasks(QList<Task *> &tasks);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

signals:
private:
    QString m_title;
    QString m_note;

    QList<Task *> m_tasks;
};

#endif // NOTE_H

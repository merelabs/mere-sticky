#ifndef NOTE_H
#define NOTE_H

#include "../../stickyglobal.h"
#include "base.h"

class MERE_STICKY_LIBSPEC Chirkut : public Base
{
public:
    ~Chirkut();
    explicit Chirkut();

    QString title() const;
    void setTitle(const QString &title);

    QString note() const;
    void setNote(const QString &note);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

signals:
private:
    QString m_title;
    QString m_note;
};

#endif // NOTE_H

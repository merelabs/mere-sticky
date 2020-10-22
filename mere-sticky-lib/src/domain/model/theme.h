#ifndef THEME_H
#define THEME_H

#include "base.h"

class MERE_STICKY_LIBSPEC Theme : public Base
{
public:
    ~Theme();
    Theme();

    QString code() const;
    void setCode(const QString &code);

    QString name() const;
    void setName(const QString &name);

    QString foreground() const;
    void setForeground(const QString &color);

    QString background() const;
    void setBackground(const QString &color);

    QMap<QString, QVariant> attributes() const;
    void setAttributes(QMap<QString, QVariant> attrs);

private:
    QString m_code;
    QString m_name;
    QString m_foreground;
    QString m_background;
};

#endif // THEME_H

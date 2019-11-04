#ifndef MERESTICKYSCHEME_H
#define MERESTICKYSCHEME_H

#include <QUuid>
#include <QFont>
#include <QColor>
#include <QObject>

class MereStickyTheme : public QObject
{
    Q_OBJECT
public:
    explicit MereStickyTheme(QObject *parent = nullptr);

    QUuid uid() const;

    QString name() const;
    void setName(QString name);

    QColor backgroundColor() const;
    void setBackgroundColor(QColor color);

    QColor borderColor() const;
    void setBorderColor(QColor color);

signals:

public slots:

private:
    QUuid m_uid;
    QString m_name;
    QColor m_backgroundcolor;
    QColor m_borderColor;
};

#endif // MERESTICKYSCHEME_H

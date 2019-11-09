#ifndef MERESTICKYTHEMEUNIT_H
#define MERESTICKYTHEMEUNIT_H

#include <QUuid>
#include <QFont>
#include <QColor>
#include <QObject>

class MereStickyThemeUnit : public QObject
{
    Q_OBJECT
public:
    explicit MereStickyThemeUnit(QObject *parent = nullptr);

    QUuid uid() const;

    QString code() const;
    void setCode(QString code);

    QString name() const;
    void setName(QString name);

    QColor foregroundColor() const;
    void setForegroundColor(QColor color);

    QColor backgroundColor() const;
    void setBackgroundColor(QColor color);

    QColor borderColor() const;
    void setBorderColor(QColor color);

signals:

public slots:
private:
    QUuid m_uid;
    QString m_code;
    QString m_name;
    QColor m_backgroundcolor;
    QColor m_foregroundcolor;
    QColor m_borderColor;
};

#endif // MERESTICKYTHEMEUNIT_H

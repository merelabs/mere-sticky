#include "merestickytheme.h"

MereStickyTheme::MereStickyTheme(QObject *parent)
    : QObject(parent)
{
    m_uid = QUuid::createUuid();
}

QUuid MereStickyTheme::uid() const
{
    return m_uid;
}

QString MereStickyTheme::name() const
{
    return m_name;
}

void MereStickyTheme::setName(QString name)
{
    m_name = name;
}

QColor MereStickyTheme::backgroundColor() const
{
    return m_backgroundcolor;
}

void MereStickyTheme::setBackgroundColor(QColor color)
{
    m_backgroundcolor = color;
}

QColor MereStickyTheme::borderColor() const
{
    return m_borderColor;
}

void MereStickyTheme::setBorderColor(QColor color)
{
    m_borderColor = color;
}

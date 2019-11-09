#include "merestickythemeunit.h"

MereStickyThemeUnit::MereStickyThemeUnit(QObject *parent) : QObject(parent)
{
    m_uid = QUuid::createUuid();
}

QUuid MereStickyThemeUnit::uid() const
{
    return m_uid;
}

QString MereStickyThemeUnit::name() const
{
    return m_name;
}

void MereStickyThemeUnit::setName(QString name)
{
    m_name = name;
}

QColor MereStickyThemeUnit::backgroundColor() const
{
    return m_backgroundcolor;
}

void MereStickyThemeUnit::setBackgroundColor(QColor color)
{
    m_backgroundcolor = color;
}

QColor MereStickyThemeUnit::borderColor() const
{
    return m_borderColor;
}

void MereStickyThemeUnit::setBorderColor(QColor color)
{
    m_borderColor = color;
}

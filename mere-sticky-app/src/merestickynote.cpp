#include "merestickynote.h"

#include <QSize>

MereStickyNote::MereStickyNote(QWidget *parent)
    : QTextEdit(parent)
{
//    m_resizer = new MereWidgetResizer(this, this);
//    QWidget *widget = new QWidget;
//    widget->setMinimumSize(12,12);
//    widget->setMaximumSize(12,12);
//    widget->setStyleSheet("background-color:gray");
//    setCornerWidget(m_resizer);
//    m_resizer->raise();
}

void MereStickyNote::setResizer(MereWidgetResizer *resizer)
{
//    this->setCornerWidget(resizer);
}

void MereStickyNote::adjustSize(const QSize &size)
 {
//   setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );

//   resize(this->size().width() + size.width(), this->size().height() + size.height());
//   updateGeometry();
 }

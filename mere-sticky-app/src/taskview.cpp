#include "taskview.h"
#include "mere/widgets/mereeditablelabel.h"

#include <QPushButton>
#include <QHBoxLayout>

TaskView::TaskView(QWidget *parent) : QWidget(parent)
{
    setObjectName(QString::fromUtf8("MereStickyNoteTask"));

    setMaximumHeight(30);

    QPalette p = palette();
    p.setColor( QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette( p );

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);

    initUI();
}

void TaskView::initUI()
{
    m_mark = new QPushButton(this);
    m_mark->setObjectName(QString::fromUtf8("MereStickyNoteTaskMark"));

    m_mark->setMinimumSize(QSize(16, 16));
    m_mark->setMaximumSize(QSize(16, 16));
    m_mark->setFlat(true);

    layout()->addWidget(m_mark);

    m_title = new MereEditableLabel(this);
    m_title->setObjectName(QString::fromUtf8("MereStickyNoteTaskTitle"));
    m_title->setText(QString::fromUtf8("** enter your check item here **"));
    m_title->setIndent(0);
    m_title->setOpenExternalLinks(true);

    layout()->addWidget(m_title);

//    QPushButton *priority = new QPushButton(this);
//    priority->setMaximumWidth(100);
//    priority->setObjectName(QString::fromUtf8("MereStickyNoteTaskPriority"));
////    priority->setMinimumSize(QSize(16, 16));
////    priority->setMaximumSize(QSize(16, 16));
////    priority->setFlat(true);
//    priority->setText("priority");
//    priority->setStyleSheet("#MereStickyNoteTaskPriority{ border-radius:10px; background-color:red;}");
//    layout()->addWidget(priority);
}

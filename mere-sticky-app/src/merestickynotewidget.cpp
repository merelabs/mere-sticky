#include "merestickynotewidget.h"
#include "merestickynote.h"

#include <QVBoxLayout>
MereStickyNoteWidget::~MereStickyNoteWidget()
{
}

MereStickyNoteWidget::MereStickyNoteWidget(QWidget *parent) :
    QWidget(parent)
{
    setObjectName(QString::fromUtf8("MereStickyNoteWidget"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    initUI();
}

void MereStickyNoteWidget::initUI()
{
    stickyNote = new MereStickyNote(this);
    layout()->addWidget(stickyNote);
}

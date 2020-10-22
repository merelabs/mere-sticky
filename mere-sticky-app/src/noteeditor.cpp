#include "noteeditor.h"


NoteEditor::NoteEditor(QWidget *parent)
    : Mere::Widgets::NoteEditor(parent)
{
    setObjectName(QString::fromUtf8("MereStickyNoteEditor"));

    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, QColor(0, 0, 0, 50));
    palette.setColor(QPalette::Window, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette(palette);
}

#include "noteeditor.h"

NoteEditor::NoteEditor(QWidget *parent)
    : MereNoteEditor(parent)
{
    setObjectName(QString::fromUtf8("MereStickyNote"));
}

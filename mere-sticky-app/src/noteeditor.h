#ifndef MERESTICKYNOTE_H
#define MERESTICKYNOTE_H

#include "mere/widgets/merenoteeditor.h"

#include <QDebug>

class NoteEditor : public MereNoteEditor
{
    Q_OBJECT
public:
    explicit NoteEditor(QWidget *parent = nullptr);
};

#endif // MERESTICKYNOTE_H

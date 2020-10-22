#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include "mere/widgets/noteeditor.h"

#include <QDebug>
class NoteEditor : public Mere::Widgets::NoteEditor
{
    Q_OBJECT
public:
    explicit NoteEditor(QWidget *parent = nullptr);
};

#endif // NOTEEDITOR_H

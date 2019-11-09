#ifndef MERESTICKYNOTE_H
#define MERESTICKYNOTE_H

#include "mere/widgets/merenoteeditor.h"

#include <QDebug>

class MereStickyNote : public MereNoteEditor
{
    Q_OBJECT
public:
    explicit MereStickyNote(QWidget *parent = nullptr);
};

#endif // MERESTICKYNOTE_H

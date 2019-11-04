#ifndef MERESTICKYNOTE_H
#define MERESTICKYNOTE_H

#include "mere/widgets/merewidgetresizer.h"

#include <QDebug>
#include <QTextEdit>

class MereStickyNote : public QTextEdit, public MereResizeableWidget
{
    Q_OBJECT
public:
    explicit MereStickyNote(QWidget *parent = nullptr);
    void setResizer(MereWidgetResizer *resizer);
    void adjustSize(const QSize &size);

signals:

public slots:
private:
    MereWidgetResizer *m_resizer;

};

#endif // MERESTICKYNOTE_H

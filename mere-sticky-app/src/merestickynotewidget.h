#ifndef MERESTICKYNOTEWIDGET_H
#define MERESTICKYNOTEWIDGET_H

#include <QTextEdit>
#include <QWidget>

class MereStickyNote ;

class MereStickyNoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MereStickyNoteWidget(QWidget *parent = 0);
    ~MereStickyNoteWidget();

private:
    void initUI();

private:
    MereStickyNote *stickyNote;
};

#endif // MERESTICKYNOTEWIDGET_H

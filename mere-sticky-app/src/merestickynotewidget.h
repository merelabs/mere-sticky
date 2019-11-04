#ifndef MERESTICKYNOTEWIDGET_H
#define MERESTICKYNOTEWIDGET_H

#include <QTextEdit>
#include <QWidget>

//namespace Ui {
//class MereStickyNoteWidget;
//}

class MereStickyNote ;

class MereStickyNoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MereStickyNoteWidget(QWidget *parent = 0);
    ~MereStickyNoteWidget();

private:
    void setupContextMenu();

private slots:
    void showContextMenu(const QPoint &pt);

private:
//    Ui::MereStickyNoteWidget *ui;
        MereStickyNote *stickyNote;
};

#endif // MERESTICKYNOTEWIDGET_H

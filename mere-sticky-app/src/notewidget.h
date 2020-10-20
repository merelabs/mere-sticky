#ifndef MERESTICKYNOTEWIDGET_H
#define MERESTICKYNOTEWIDGET_H

#include <QWidget>

class NoteEditor ;

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    ~NoteWidget();
    explicit NoteWidget(QWidget *parent = 0);

    QString content() const;
    void setContent(const QString &content);

private:
    void initUI();

private:
    NoteEditor *m_editor;
};

#endif // MERESTICKYNOTEWIDGET_H

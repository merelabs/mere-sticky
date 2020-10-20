#ifndef CHECKLIST_H
#define CHECKLIST_H

#include <QWidget>

class CheckListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckListWidget(QWidget *parent = nullptr);

private:
    void initUI();

    void initHeader();
    void initContent();
signals:

};

#endif // CHECKLIST_H

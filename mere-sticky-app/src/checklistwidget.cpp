#include "checklistwidget.h"
#include "taskview.h"

#include <QIcon>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

CheckListWidget::CheckListWidget(QWidget *parent) : QWidget(parent)
{
    QPalette p = palette();
    p.setColor( QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette( p );

//    setMaximumHeight(30);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);

    setLayout(layout);

    initUI();
}

void CheckListWidget::initUI()
{
    initHeader();
    initContent();
}

void CheckListWidget::initHeader()
{
    QWidget *header = new QWidget();
    layout()->addWidget(header);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);
    layout->setAlignment(Qt::AlignLeft);

    header->setLayout(layout);

    QLabel *icon = new QLabel;
    QPixmap pixmap = QIcon(":/sticky/down.png").pixmap(QSize(QSize(16, 16)));
    icon->setPixmap(pixmap);

    layout->addWidget(icon);

    QLabel *label = new QLabel;
    label->setText("Checklist");
    layout->addWidget(label);

    QPushButton *button = new QPushButton();
    button->setText("+");
    layout->addWidget(button);
//    connect(button, SIGNAL(clicke))
}

void CheckListWidget::initContent()
{
    TaskView *task1 = new TaskView();
    layout()->addWidget(task1);

    TaskView *task2 = new TaskView();
    layout()->addWidget(task2);

    TaskView *task3 = new TaskView();
    layout()->addWidget(task3);
}

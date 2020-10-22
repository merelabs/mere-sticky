#include "themeview.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/service/themeservice.h"

#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>

ThemeView::~ThemeView()
{

}

ThemeView::ThemeView(Theme &theme, QWidget *parent)
    : QWidget(parent),
      m_theme(theme)
{
    setObjectName(QString::fromUtf8("MereStickyNoteTask"));

    setMinimumHeight(36);
    setMaximumHeight(36);

    QPalette p = palette();
    p.setColor(QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette(p);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(10);

    initUI();
}

void ThemeView::initUI()
{
    qDebug() << " KI BOLE??";
//    QString color = "white";
//    if (m_task.mark() == Task::Mark::Doing)
//        color = "yellow";
//    else if (m_task.mark() == Task::Mark::Done)
//        color = "green";

//    m_mark = new QPushButton(this);
//    m_mark->setObjectName(QString::fromUtf8("MereStickyNoteTaskMark"));
//    m_mark->setMaximumSize(QSize(16, 16));
//    m_mark->setFlat(true);
//    m_mark->setStyleSheet("#MereStickyNoteTaskMark{ border-radius:8px; background-color:"+ color +";}");
//    layout()->addWidget(m_mark);

    m_name = new Mere::Widgets::EditableLabel(this);
    m_name->setText(m_theme.name());

    layout()->addWidget(m_name);

//    QLabel *updatedAt = new QLabel(this);
//    updatedAt->setObjectName(QString::fromUtf8("MereStickyNoteTaskUpdatedAt"));
//    updatedAt->setMaximumWidth(75);
//    updatedAt->setMaximumHeight(20);
//    updatedAt->setAlignment(Qt::AlignCenter);

//    QFont font = updatedAt->font();
//    font.setPointSize(6);
//    updatedAt->setFont(font);

//    updatedAt->setText(m_task.updatedAt().toString("MMM dd"));
//    updatedAt->setStyleSheet("#MereStickyNoteTaskUpdatedAt{ border-radius:10px; background-color:cyan;}");
//    layout()->addWidget(updatedAt);

//    QPushButton *btnMarkEx = new QPushButton(this);
//    btnMarkEx->setObjectName(QString::fromUtf8("MereStickyNoteTaskMarkEx"));
//    btnMarkEx->setMaximumWidth(75);
//    btnMarkEx->setMaximumHeight(20);
////    status->setAlignment(Qt::AlignCenter);

//    QFont statusFont;// = updatedAt->font();
//    statusFont.setPointSize(6);
//    btnMarkEx->setFont(statusFont);

//    QString mark = "Open";
//    if (m_task.mark() == Task::Mark::Doing)
//        mark = "Doing";
//    else if (m_task.mark() == Task::Mark::Done)
//        mark = "Done";

//    btnMarkEx->setText(mark);

//    btnMarkEx->setStyleSheet("#MereStickyNoteTaskMarkEx{ border-radius:10px; background-color:"+ color +";}");
//    layout()->addWidget(btnMarkEx);

    QPushButton *btnRemove = new QPushButton();
    btnRemove->setIcon(QIcon(":/sticky/delete.png"));
    btnRemove->setIconSize(QSize(16, 16));
    btnRemove->setFlat(true);
    btnRemove->setMaximumSize(QSize(16, 16));

    layout()->addWidget(btnRemove);

//    connect(m_mark, SIGNAL(clicked()), this, SLOT(updateTaskMark()));
//    connect(m_title, SIGNAL(changed()), this, SLOT(updateTaskTitle()));
//    connect(btnMarkEx, SIGNAL(clicked()), this, SLOT(updateTaskMark()));
    connect(btnRemove, SIGNAL(clicked()), this, SLOT(removeTheme()));
}

bool ThemeView::removeTheme()
{
    QMessageBox msgBox(QMessageBox::Question,
                       tr(""),
                       tr("Do you want to delete it?"),
                       QMessageBox::Yes | QMessageBox::No, this,
                       Qt::FramelessWindowHint);

    if (QMessageBox::No == msgBox.exec())
        return false;

    ThemeService service;
    bool ok = service.remove(m_theme);
    if (!ok) return false;

    emit removed(m_theme);
    this->deleteLater();

    return true;
}

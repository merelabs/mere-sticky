#include "merestickymorewidget.h"

#include <QIcon>
#include <QHBoxLayout>
#include <QApplication>
#include <QPushButton>
#include <QAction>
#include <QMenu>

MereStickyMoreWidget::~MereStickyMoreWidget()
{

}

MereStickyMoreWidget::MereStickyMoreWidget(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QString::fromUtf8("MereStickyMoreWidget"));
    resize(28, 24);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    initUI();
}

void MereStickyMoreWidget::initUI()
{
    moreOption = new QPushButton(this);
    moreOption->setObjectName(QString::fromUtf8("moreOption"));
    moreOption->setMinimumSize(QSize(16, 16));
    moreOption->setMaximumSize(QSize(16, 16));
    moreOption->setText(QString::fromUtf8(""));
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/sticky/more.png"), QSize(), QIcon::Normal, QIcon::Off);
    moreOption->setIcon(icon);
    moreOption->setFlat(true);
    moreOption->setStyleSheet("::menu-indicator{ image: none; }");

    layout()->addWidget(moreOption);

    setupMoreOption(moreOption);
}

void MereStickyMoreWidget::setupMoreOption(QPushButton *moreOption)
{
    QIcon newNoteIcon(":/sticky/new.png");
    QAction* newNoteAction = new QAction(newNoteIcon, tr("&New Note"), this);
    newNoteAction->setToolTip(tr("Open new note window"));
    newNoteAction->setShortcut(QKeySequence(tr("Alt+N")));
    newNoteAction->setShortcutVisibleInContextMenu(true);
    connect(newNoteAction, SIGNAL(triggered()), this, SLOT(record()));

    QIcon confNoteIcon(":/sticky/config.png");
    QAction* configAction = new QAction(confNoteIcon, tr("&Settings"), this);
//    configAction->setToolTip(tr("Configure "));
//    configAction->setShortcut(QKeySequence(tr("Alt+S")));
    configAction->setShortcutVisibleInContextMenu(true);
    connect(configAction, SIGNAL(triggered()), this, SLOT(record()));

//    QIcon aboutIcon(":/sticky/new.png");
//    QAction* aboutAction  = new QAction(aboutIcon, tr("About"), this);

//    QIcon helpIcon(":/sticky/new.png");
//    QAction* helpAction   = new QAction(helpIcon, tr("Help"), this);

    QIcon exitNoteIcon(":/sticky/quit.png");
    QAction* exitNoteAction = new QAction(exitNoteIcon, tr("&Exit"), this);
    exitNoteAction->setShortcut(QKeySequence(tr("Ctrl+Shift+Q")));
    exitNoteAction->setShortcutVisibleInContextMenu(true);
    connect(exitNoteAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *menu = new QMenu(moreOption);
    menu->addAction(newNoteAction);
    menu->addSeparator();
    menu->addAction(configAction);
//    menu->addAction(aboutAction);
//    menu->addAction(helpAction);
    menu->addSeparator();
    menu->addAction(exitNoteAction);

    moreOption->setMenu(menu);
}

void MereStickyMoreWidget::on_moreOption_clicked()
{
    qDebug() << "More option clicked...";
}


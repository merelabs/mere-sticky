#include "merestickynotewidget.h"
//#include "ui_merestickynotewidget.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "merestickynote.h"

#include <QMenu>
#include <QLabel>

MereStickyNoteWidget::~MereStickyNoteWidget()
{
//    delete ui;
}

MereStickyNoteWidget::MereStickyNoteWidget(QWidget *parent) :
    QWidget(parent)/*,
    ui(new Ui::MereStickyNoteWidget)*/
{
//    ui->setupUi(this);
    QVBoxLayout *verticalLayout;


    setObjectName(QString::fromUtf8("MereStickyNoteWidget"));
    resize(400, 177);
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(1);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(1, 1, 1, 1);
    stickyNote = new MereStickyNote(this);
    stickyNote->setObjectName(QString::fromUtf8("stickyNote"));
    stickyNote->setStyleSheet(QString::fromUtf8("#stickyNote\n"
"{\n"
"	background-color: transparent;\n"
"}"));
    stickyNote->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>"));

    verticalLayout->addWidget(stickyNote);


    setupContextMenu();

//    setStyleSheet(QString::fromUtf8("QScrollBar:vertical {"
//        "    border: none;"
//        "    background:transparent;"
//        "    width:8px;    "
//        "    margin: 0px 0px 0px 0px;"
//        "}"
//        "QScrollBar::handle:vertical {"
//        "    border-radius: 4px;"
//        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//        "    stop: 0 rgba(0, 0, 0, 50), stop: 0.5 rgba(0, 0, 0, 50), stop:1 rgba(0, 0, 0, 50));"
//        "    min-height: 0px;"
//        "}"
//        "QScrollBar::add-line:vertical {"
//        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//        "    stop: 0 rgba(0, 0, 0, 50), stop: 0.5 rgba(0, 0, 0, 50),  stop:1 rgba(0, 0, 0, 50));"
//        "    height: 0px;"
//        "    subcontrol-position: bottom;"
//        "    subcontrol-origin: margin;"
//        "}"
//        "QScrollBar::sub-line:vertical {"
//        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
//        "    stop: 0  rgba(0, 0, 0, 50), stop: 0.5 rgba(0, 0, 0, 50),  stop:1 rgba(0, 0, 0, 50));"
//        "    height: 0 px;"
//        "    subcontrol-position: top;"
//        "    subcontrol-origin: margin;"
//        "}"
//        ));

}

void MereStickyNoteWidget::setupContextMenu()
{
//    ui->stickyNote->setContextMenuPolicy(Qt::Cu);
//    connect(ui->stickyNote,SIGNAL(customContextMenuRequest(const QPoint&)),
//                this, SLOT(showContextMenu(const QPoint &)));
}


void MereStickyNoteWidget::showContextMenu(const QPoint &pt)
{
    QMenu *menu = stickyNote->createStandardContextMenu();
//    menu->addAction(clear);
    menu->exec(stickyNote->mapToGlobal(pt));
    delete menu;
}

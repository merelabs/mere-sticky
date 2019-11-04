#include "merestickytitle.h"

#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTextDocument>

MereStickyTitle::~MereStickyTitle()
{

}

MereStickyTitle::MereStickyTitle(QWidget *parent)
    : QLabel(parent)
{
    installEventFilter(this);
}

bool MereStickyTitle::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent *mouse = static_cast<QMouseEvent *>(event);
        makeEditable(true);
        return true;
    }
    else if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key = static_cast<QKeyEvent *> (event);
        if ( key->key()==Qt::Key_Enter || key->key()==Qt::Key_Return ||
             key->key()==Qt::Key_Tab || key->key()==Qt::Key_Escape )
        {
            makeEditable(false);
            return true;
        }
    }

    return QObject::eventFilter(object, event);
}

void MereStickyTitle::makeEditable(bool flag)
{
    if (flag)
    {
        this->setTextInteractionFlags(Qt::TextEditable |
                                      Qt::TextSelectableByKeyboard |
                                      Qt::TextSelectableByMouse);
        this->setSelection(0, this->text().size());
        this->setMouseTracking(true);
        this->setCursor(Qt::IBeamCursor);
    }
    else
    {
        updateDirtyText();
        this->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        this->setCursor(Qt::ArrowCursor);
    }
}

void MereStickyTitle::updateDirtyText()
{
    QList<QTextDocument*> list = findChildren<QTextDocument*>();
    foreach(QTextDocument* textDocument, list)
    {
        this->setText(textDocument->toPlainText());
        break;
    }
}

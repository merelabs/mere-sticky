#include "notewidget.h"
#include "noteeditor.h"

#include <QVBoxLayout>

NoteWidget::~NoteWidget()
{
    if (m_editor)
    {
        delete m_editor;
        m_editor = nullptr;
    }
}

NoteWidget::NoteWidget(QWidget *parent)
    : QWidget(parent),
      m_editor(nullptr)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    initUI();
}

void NoteWidget::initUI()
{
    m_editor = new NoteEditor(this);
    layout()->addWidget(m_editor);
}

QString NoteWidget::content() const
{
    return m_editor->content();
}

void NoteWidget::setContent(const QString &content)
{
    m_editor->setContent(content);
}

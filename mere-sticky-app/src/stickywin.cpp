#include "stickywin.h"
#include "stickyapp.h"
#include "searchview.h"
#include "noteeditor.h"
#include "stickywinheader.h"
#include "tasklistview.h"

#include "mere/sticky/domain/model/issue.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/service/issueservice.h"

#include <QIcon>
#include <QPixmap>
#include <QScreen>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QGuiApplication>

StickyWin::~StickyWin()
{
    if (m_titleWidget)
    {
        delete m_titleWidget;
        m_titleWidget = nullptr;
    }

    if (m_noteEditor)
    {
        delete m_noteEditor;
        m_noteEditor = nullptr;
    }

    if (m_searchView)
    {
        delete m_searchView;
        m_searchView = nullptr;
    }
}

StickyWin::StickyWin(Issue &issue, QWidget *parent)
    : Mere::Widgets::ResizeableWin(parent),
      m_chirkut(issue),
      m_titleWidget(nullptr),
      m_noteEditor(nullptr),
      m_searchView(nullptr)
{
    setObjectName(QString::fromUtf8("MereStickyWin"));
    layout()->setContentsMargins(5, 5, 5, 5);
    layout()->setSpacing(3);
    resize();

    initUI();
}

void StickyWin::initHeaderUI()
{
    m_titleWidget = new StickyWinHeader(this);
    m_titleWidget->setObjectName(QString::fromUtf8("MereStickyTitle"));
    m_titleWidget->setTitle(m_chirkut.title());

    layout()->addWidget(m_titleWidget);
    connect(m_titleWidget, SIGNAL(themeSelected(const Theme &)), this, SLOT(applyTheme(const Theme &)));
    connect(m_titleWidget, SIGNAL(closed()), this, SLOT(close()));
}

void StickyWin::initContentUI()
{
    m_noteEditor = new NoteEditor(this);
    m_noteEditor->setContent(m_chirkut.note());
    layout()->addWidget(m_noteEditor);
}

void StickyWin::initFooterUI()
{
    TaskListView *widget = new TaskListView(m_chirkut, this);
    layout()->addWidget(widget);
}

void StickyWin::init()
{

}

void StickyWin::resize()
{
    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    QSize screenSize = primaryScreen->availableSize();

    int width = screenSize.width()/3;
    if (width < 320) width = 320;

    int height = screenSize.height()/3;
    if (height < 180) height= 180;

    QWidget::resize(width, height);
}

void StickyWin::applyTheme(const Theme &theme)
{
    QString color = theme.foreground();
    m_titleWidget->setStyleSheet("#MereStickyTitle{color:" + color + ";}");

    QString background = theme.background();
    this->setStyleSheet("#MereStickyWin{background-color:" + background + ";}");
}

void StickyWin::close()
{
    IssueService service;

    m_chirkut.setTitle(m_titleWidget->title());
    m_chirkut.setNote(m_noteEditor->content());

    service.save(m_chirkut);
}

void StickyWin::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_N  && (e->modifiers() & Qt::ControlModifier))
    {
        StickyApp *app = static_cast<StickyApp *>(qApp);
        app->newNote();

        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_W && (e->modifiers() & Qt::ControlModifier))
    {
        close();
        this->deleteLater();

        StickyApp *app = static_cast<StickyApp *>(qApp);
        app->closeNote(m_chirkut);
        app->closeNote(*this);

        e->accept(); // set as 'handled here'
        return;
    }
    else if (e->key() == Qt::Key_F && (e->modifiers() & Qt::ControlModifier))
    {
        if (m_searchView)
        {
            QRect rect = this->geometry();
            rect.setWidth(rect.width() - 250);
            this->setGeometry(rect);

            layout()->setContentsMargins(5, 5, 5, 5);
            delete m_searchView;
            m_searchView = nullptr;
        }
        else
        {
            QRect rect = this->geometry();
            rect.setWidth(rect.width() + 250);
            this->setGeometry(rect);

            layout()->setContentsMargins(255, 5, 5, 5);
            m_searchView = new SearchView(this);
            m_searchView->show();
        }

        e->accept(); // set as 'handled here'
        return;
    }

    e->ignore(); // set as 'not handled here'
}

void StickyWin::resizeEvent(QResizeEvent* event)
{
    Mere::Widgets::ResizeableWin::resizeEvent(event);
    if (m_searchView)
    {
        m_searchView->resize(layout()->contentsMargins().left(), this->size().height());
    }
}

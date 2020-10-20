#include "stickywin.h"
#include "notewidget.h"
#include "winheader.h"
#include "checklistwidget.h"

#include "mere/sticky/domain/model/chirkut.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/service/chirkutservice.h"

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

    if (m_noteWidget)
    {
        delete m_noteWidget;
        m_noteWidget = nullptr;
    }
}

StickyWin::StickyWin(Chirkut &chirkut, QWidget *parent)
    : MereResizeableWin(parent),
      m_chirkut(chirkut),
      m_titleWidget(nullptr),
      m_noteWidget(nullptr)
{
    setObjectName(QString::fromUtf8("MereStickyWin"));
    layout()->setContentsMargins(5, 5, 5, 5);
    layout()->setSpacing(3);

    resize();

    initUI();
}

void StickyWin::initHeaderUI()
{
    m_titleWidget = new WinHeader(this);
    m_titleWidget->setObjectName(QString::fromUtf8("MereStickyTitle"));
    m_titleWidget->setTitle(m_chirkut.title());

    layout()->addWidget(m_titleWidget);
    connect(m_titleWidget, SIGNAL(themeSelected(const Theme &)), this, SLOT(applyTheme(const Theme &)));
    connect(m_titleWidget, SIGNAL(closed()), this, SLOT(close()));
}

void StickyWin::initContentUI()
{
    m_noteWidget = new NoteWidget(this);
    m_noteWidget->setContent(m_chirkut.note());
    layout()->addWidget(m_noteWidget);

    CheckListWidget *widget = new CheckListWidget(this);
    layout()->addWidget(widget);
}

void StickyWin::initFooterUI()
{

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
    ChirkutService service;

    m_chirkut.setTitle(m_titleWidget->title());
    m_chirkut.setNote(m_noteWidget->content());
    service.save(m_chirkut);
}

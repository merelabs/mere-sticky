#include "themelistwidget.h"
#include "themeview.h"

#include "stickywinheader.h"
#include "mere/sticky/domain/model/theme.h"
#include "mere/sticky/domain/store/themestore.h"
#include "mere/sticky/service/themeservice.h"

#include <QFuture>
#include <QtConcurrent>
#include <QInputDialog>
#include <QVBoxLayout>

ThemeListWidget::~ThemeListWidget()
{
    qDeleteAll(m_themes);
}

ThemeListWidget::ThemeListWidget(QWidget *parent)
    : ResizeableWin(parent)
{
    setObjectName(QString::fromUtf8("MereStickyNoteThemeListWidget"));
    layout()->setContentsMargins(5, 5, 5, 5);
    layout()->setSpacing(3);

    resize(400, 300);

    init();
    initUI();
}

void ThemeListWidget::init()
{
    QFuture<QList<Theme *> > future = QtConcurrent::run([=]{
        BaseService service;

        return service.list<ThemeStore, Theme>();
    });

    future.waitForFinished();

    m_themes = future.result();
    qDebug() << "Number of themes found:" << m_themes.size();
}

void ThemeListWidget::initHeaderUI()
{
    StickyWinHeader *m_titleWidget = new StickyWinHeader(this);
    m_titleWidget->setObjectName(QString::fromUtf8("MereStickyTitle"));

    layout()->addWidget(m_titleWidget);
    connect(m_titleWidget, SIGNAL(closed()), this, SLOT(close()));
}

void ThemeListWidget::initContentUI()
{
    m_contentWidget = new QWidget();

    layout()->addWidget(m_contentWidget);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(5);
    m_contentWidget->setLayout(layout);

    updateContentUI();
}

void ThemeListWidget::initFooterUI()
{

}

void ThemeListWidget::updateContentUI()
{
    // clear
    qDeleteAll(m_contentWidget->findChildren<ThemeView *>());

    QListIterator<Theme *> it(m_themes);
    while (it.hasNext())
    {
        Theme *theme = it.next();
        ThemeView *themeView = new ThemeView(*theme);
        connect(themeView, SIGNAL(removed(const Theme &)), this, SLOT(removeTheme(const Theme &)));
        m_contentWidget->layout()->addWidget(themeView);
    }
}


bool ThemeListWidget::addTheme()
{
    bool ok;

    QString text = QInputDialog::getText(this, "",
                                       tr("Enter the item to be checked:"), QLineEdit::Normal,
                                       "", &ok, Qt::CustomizeWindowHint);
    if (!ok || text.isEmpty()) return false;

//    Theme *task = new Task();
//    task->setMark(Task::Mark::Open);
//    task->setTitle(text);

//    m_themes.append(task);

//    IssueService service;
//    QUuid uuid = service.save(m_issue);
//    if (!uuid.isNull())
//    {
//        updateContentUI();
//    }

    return ok;
}

bool ThemeListWidget::removeTheme(const Theme &theme)
{
    bool ok = false;

    QMutableListIterator<Theme *> it(m_themes);
    while (it.hasNext())
    {
        Theme *_theme = it.next();
        if (!_theme) continue;

        if (_theme->id() == theme.id())
        {
            it.remove();
            ok = true;
            break;
        }
    }

    return ok;
}

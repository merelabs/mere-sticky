#include "merestickywin.h"
#include "merestickynotewidget.h"
#include "merestickytitlewidget.h"
#include "mere/sticky/merestickytheme.h"

#include <QMouseEvent>
#include <QVBoxLayout>

MereStickyWin::MereStickyWin(QWidget *parent)
    : QWidget(parent),
      m_lock(true)
{
    setObjectName(QString::fromUtf8("MereStickyWin"));
    setWindowFlags(Qt::FramelessWindowHint);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(9, 9, 9, 9);

    initUI();

    m_resizer = new MereWidgetResizer(this, this);
}

void MereStickyWin::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();

//    QVBoxLayout *verticalLayout;

    resize(300, 175);
//    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    sizePolicy.setHorizontalStretch(0);
//    sizePolicy.setVerticalStretch(0);
//    sizePolicy.setHeightForWidth(MereStickyWidget->sizePolicy().hasHeightForWidth());
//    MereStickyWidget->setSizePolicy(sizePolicy);
//    MereStickyWidget->setStyleSheet(QString::fromUtf8(""));

    stickyTitleWidget = new MereStickyTitleWidget(this);
//    stickyTitleWidget->setObjectName(QString::fromUtf8("stickyTitleWidget"));
//    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
//    sizePolicy1.setHorizontalStretch(0);
//    sizePolicy1.setVerticalStretch(0);
//    sizePolicy1.setHeightForWidth(stickyTitleWidget->sizePolicy().hasHeightForWidth());
//    stickyTitleWidget->setSizePolicy(sizePolicy1);

    layout()->addWidget(stickyTitleWidget);

    stickyNoteWidget = new MereStickyNoteWidget(this);
//    stickyNoteWidget->setObjectName(QString::fromUtf8("stickyNoteWidget"));

    layout()->addWidget(stickyNoteWidget);


    connect(stickyTitleWidget, SIGNAL(themeSelected(MereStickyTheme *)), this, SLOT(applyTheme(MereStickyTheme *)));
}

void MereStickyWin::initHeaderUI()
{
}

void MereStickyWin::initContentUI()
{
}

void MereStickyWin::initFooterUI()
{

}

void MereStickyWin::init()
{

}

void MereStickyWin::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_resizer->move( event->size().width() - m_resizer->width(),
    event->size().height() - m_resizer->height() );

    event->accept();
}

void MereStickyWin::setResizer(MereWidgetResizer *resizer)
{
//    qDebug() << "YES SET RESIZER!!!!";
}

void MereStickyWin::adjustSize(const QSize &size)
{
    resize(width() + size.width(), height() + size.height());
}

void MereStickyWin::enterEvent(QEvent *event)
{

}

void MereStickyWin::leaveEvent(QEvent *event)
{

}

void MereStickyWin::mousePressEvent(QMouseEvent *event)
{
    m_lock = false;
    m_point = event->globalPos();
}

void MereStickyWin::mouseReleaseEvent(QMouseEvent *event)
{
    m_lock = true;

}
void MereStickyWin::mouseMoveEvent(QMouseEvent *event)
{
    if (m_lock) return;

    QPoint point = event->globalPos();
    move(pos() + point - m_point);
    m_point = point;
}

void MereStickyWin::applyTheme(MereStickyTheme *theme)
{
    QColor color = theme->backgroundColor();
    this->setStyleSheet("#MereStickyWin{background-color:" + color.name() + ";}");
}

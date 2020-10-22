#include "issuelineview.h"
#include "stickyapp.h"

#include "mere/sticky/domain/model/issue.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

IssueLineView::IssueLineView(Issue &issue, QWidget *parent)
    : QWidget(parent),
      m_issue(issue)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, Qt::red);
    palette.setColor(QPalette::Window, Qt::red);
    setAutoFillBackground(true);
    setPalette(palette);

//    setMinimumHeight(75);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);

    initUI();
}

void IssueLineView::initUI()
{
    initHeader();

    QLabel *title = new QLabel();
    title->setText(m_issue.title());
    layout()->addWidget(title);
}

void IssueLineView::initHeader()
{
    QWidget *header = new QWidget();
    header->setMaximumHeight(20);
    layout()->addWidget(header);

    QHBoxLayout *layout = new QHBoxLayout(header);
    layout->setContentsMargins(3, 3, 3, 3);
    layout->setSpacing(3);

    QPushButton *detach = new QPushButton();
    detach->setIcon(QIcon(":/sticky/detach.png"));
    detach->setIconSize(QSize(16, 16));
    detach->setFlat(true);

    connect(detach, &QPushButton::clicked, [=]{
        StickyApp *app = static_cast<StickyApp *>(qApp);
        app->openNote(m_issue);
    });
    layout->addWidget(detach);

    QSpacerItem *spacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    layout->addSpacerItem(spacer);

    QPushButton *trush = new QPushButton();
    trush->setIcon(QIcon(":/sticky/trush.png"));
    trush->setIconSize(QSize(16, 16));
    trush->setFlat(true);
    connect(trush, &QPushButton::clicked, [=]{
        StickyApp *app = static_cast<StickyApp *>(qApp);
//        app->removeNote(m_issue);
    });
    layout->addWidget(trush);

}

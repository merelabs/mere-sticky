#include "searchview.h"
#include "issuelineview.h"

#include "mere/sticky/service/searchservice.h"

#include <QIcon>
#include <QLineEdit>
#include <QVBoxLayout>

SearchView::SearchView(QWidget *parent)
    : QWidget(parent)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Base, Qt::white);
    palette.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(palette);

    setMinimumWidth(parent->layout()->contentsMargins().left());
    setMinimumHeight(parent->size().height());

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    layout->setSpacing(5);

    initUI();
}

void SearchView::initUI()
{
    m_searchBox = new QLineEdit();
    m_searchBox->setPlaceholderText("Search Stiny Notes");
    m_searchBox->addAction(QIcon(":/sticky/down.png"), QLineEdit::LeadingPosition);
    m_searchBox->setClearButtonEnabled(true);

    connect(m_searchBox, SIGNAL(returnPressed()), this, SLOT(search()));

    layout()->addWidget(m_searchBox);

}

void SearchView::search()
{
    QString searchWhat = m_searchBox->text();

    searchIssues(searchWhat);
}

void SearchView::searchIssues(const QString &what)
{
    SearchService service;

    QList<Issue *> issues = service.issues(what);
    QListIterator<Issue *> it(issues);
    while(it.hasNext())
    {
        Issue *issue = it.next();
        if (!issue) continue;

        IssueLineView *view = new IssueLineView(*issue, this);
        layout()->addWidget(view);
    }

    qDebug() << "Number of issue found:" << issues.size();
}

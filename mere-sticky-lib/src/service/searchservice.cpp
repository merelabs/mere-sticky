#include "searchservice.h"
#include "issueservice.h"

SearchService::SearchService(QObject *parent)
    : BaseService(parent)
{

}

QList<Issue *> SearchService::issues(const QString &what)
{
    IssueService issueService;
    QList<Issue *> issues = issueService.find(what);

    return issues;
}

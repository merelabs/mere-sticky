#include "issuestore.h"

IssueStore::~IssueStore()
{

}

IssueStore::IssueStore(QObject *parent)
    : BaseStore("issue", parent)
{

}

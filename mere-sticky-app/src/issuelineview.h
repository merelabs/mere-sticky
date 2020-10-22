#ifndef ISSUEINLINEVIEW_H
#define ISSUEINLINEVIEW_H

#include <QWidget>

class Issue;
class IssueLineView : public QWidget
{
    Q_OBJECT
public:
    explicit IssueLineView(Issue &issue, QWidget *parent = nullptr);

private:
    void initUI();

    void initHeader();

signals:

private:
    Issue &m_issue;
};

#endif // ISSUEINLINEVIEW_H

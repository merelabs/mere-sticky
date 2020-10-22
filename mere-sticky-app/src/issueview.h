#ifndef NOTEVIEW_H
#define NOTEVIEW_H

#include <QWidget>

class Issue;
class IssueView : public QWidget
{
    Q_OBJECT
public:
    ~IssueView();
    explicit IssueView(Issue &issue, QWidget *parent = nullptr);

signals:

};

#endif // NOTEVIEW_H

#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QLineEdit>
#include <QWidget>
#include <QDebug>

class SearchView : public QWidget
{
    Q_OBJECT
public:
    explicit SearchView(QWidget *parent = nullptr);

private:
    void initUI();

    void searchIssues(const QString &what);

signals:
private slots:
    void search();

private:
    QLineEdit *m_searchBox;
};

#endif // SEARCHWIDGET_H

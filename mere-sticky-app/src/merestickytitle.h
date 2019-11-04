#ifndef MERESTICKYTITLE_H
#define MERESTICKYTITLE_H

#include <QDebug>
#include <QLabel>

class MereStickyTitle : public QLabel
{
    Q_OBJECT
public:
    ~MereStickyTitle();
    explicit MereStickyTitle(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject* object, QEvent* event) override;

private:
    void makeEditable(bool flag);
    void updateDirtyText();

signals:

public slots:
};

#endif // MERESTICKYTITLE_H

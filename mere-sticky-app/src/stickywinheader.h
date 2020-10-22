#ifndef MERESTICKYWINHEADER_H
#define MERESTICKYWINHEADER_H

#include "mere/widgets/simplewinheader.h"
#include "mere/widgets/editablelabel.h"

class Theme;
class StickyWinHeader : public Mere::Widgets::SimpleWinHeader
{
    Q_OBJECT
public:
    ~StickyWinHeader() override;
    explicit StickyWinHeader(QWidget *parent = nullptr);

    QString title() const;
    void setTitle(const QString &title);

protected:
    void initLeftPanel() override;
    void initCenterPanel() override;
    void initRightPanel() override;

signals:
    void themeSelected(const Theme &theme);

private:
    Mere::Widgets::EditableLabel *m_title;
};

#endif // MERESTICKYWINHEADER_H

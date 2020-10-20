#ifndef MERESTICKYWINHEADER_H
#define MERESTICKYWINHEADER_H

#include "mere/widgets/meresimplewinheader.h"

class Theme;
class MereEditableLabel;

class WinHeader : public MereSimpleWinHeader
{
    Q_OBJECT
public:
    ~WinHeader() override;
    explicit WinHeader(QWidget *parent = nullptr);

    QString title() const;
    void setTitle(const QString &title);

protected:
    void initLeftPanel() override;
    void initCenterPanel() override;
    void initRightPanel() override;

signals:
    void themeSelected(const Theme &theme);

private:
    MereEditableLabel *m_title;
};

#endif // MERESTICKYWINHEADER_H

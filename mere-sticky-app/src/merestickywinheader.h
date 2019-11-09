#ifndef MERESTICKYWINHEADER_H
#define MERESTICKYWINHEADER_H

#include "mere/widgets/meresimplewinheader.h"

class MereStickyTheme;

class MereStickyWinHeader : public MereSimpleWinHeader
{
    Q_OBJECT
public:
    ~MereStickyWinHeader() override;
    explicit MereStickyWinHeader(QWidget *parent = nullptr);

protected:
    void initLeftPanel() override;
    void initCenterPanel() override;
    void initRightPanel() override;

signals:
    void themeSelected(MereStickyTheme *theme);

private:

};

#endif // MERESTICKYWINHEADER_H

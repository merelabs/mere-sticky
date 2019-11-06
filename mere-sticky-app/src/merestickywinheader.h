#ifndef MERESTICKYWINHEADER_H
#define MERESTICKYWINHEADER_H

#include "mere/widgets/meresimplewinheader.h"

#include <QWidget>

class MereStickyTheme;
class MereStickyThemePicker;

class MereStickyWinHeader : public MereSimpleWinHeader
{
    Q_OBJECT
public:
    ~MereStickyWinHeader();
    explicit MereStickyWinHeader(QWidget *parent = 0);

protected:
    void initLeftPanel() override;
    void initCenterPanel() override;
    void initRightPanel() override;

signals:
    void themeSelected(MereStickyTheme *theme);

private:
    MereStickyThemePicker *m_stickyThemePickerWidget;
};

#endif // MERESTICKYWINHEADER_H

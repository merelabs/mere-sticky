#include "merestickytitlewidget.h"
#include "mere/sticky/merestickytheme.h"

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "merestickytitle.h"
#include "merestickytitleleftcontrolwidget.h"
#include "merestickytitlerightcontrolwidget.h"

#include <QPainter>
#include <QStyleOption>

MereStickyTitleWidget::~MereStickyTitleWidget()
{
//    delete ui;
}

MereStickyTitleWidget::MereStickyTitleWidget(QWidget *parent) :
    QWidget(parent)/*,
    ui(new Ui::MereStickyTitleWidget)*/
{

    QHBoxLayout *horizontalLayout;
    MereStickyTitleLeftControlWidget *stickyThemePickerWidget;
    MereStickyTitle *stickyTitle;
    MereStickyTitleRightControlWidget *widget;

//    ui->setupUi(this);

//    if (MereStickyTitleWidget->objectName().isEmpty())
//        MereStickyTitleWidget->setObjectName(QString::fromUtf8("MereStickyTitleWidget"));
    resize(300, 36);

//    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//    sizePolicy.setHorizontalStretch(0);
//    sizePolicy.setVerticalStretch(0);
//    sizePolicy.setHeightForWidth(MereStickyTitleWidget->sizePolicy().hasHeightForWidth());
//    MereStickyTitleWidget->setSizePolicy(sizePolicy);
    horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(5, 5, 5, 5);
    stickyThemePickerWidget = new MereStickyTitleLeftControlWidget(this);
    stickyThemePickerWidget->setObjectName(QString::fromUtf8("stickyThemePickerWidget"));
    QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(stickyThemePickerWidget->sizePolicy().hasHeightForWidth());
    stickyThemePickerWidget->setSizePolicy(sizePolicy1);
    stickyThemePickerWidget->setMinimumSize(QSize(18, 18));
    stickyThemePickerWidget->setMaximumSize(QSize(18, 18));
    stickyThemePickerWidget->setStyleSheet(QString::fromUtf8("#stickyThemePickerWidget\n"
"{\n"
"border-radious: 8px;\n"
"background-color:white;\n"
"}"));

    horizontalLayout->addWidget(stickyThemePickerWidget);

    stickyTitle = new MereStickyTitle(this);
    stickyTitle->setObjectName(QString::fromUtf8("stickyTitle"));
    stickyTitle->setAutoFillBackground(false);
    stickyTitle->setText(QString::fromUtf8("Mere Sticky Notes"));
    stickyTitle->setScaledContents(false);
    stickyTitle->setAlignment(Qt::AlignCenter);
    stickyTitle->setIndent(0);
    stickyTitle->setOpenExternalLinks(true);
    stickyTitle->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextEditable);

    horizontalLayout->addWidget(stickyTitle);

    widget = new MereStickyTitleRightControlWidget(this);
    widget->setObjectName(QString::fromUtf8("widget"));
    sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
    widget->setSizePolicy(sizePolicy1);
    widget->setMinimumSize(QSize(18, 18));
    widget->setMaximumSize(QSize(18, 18));

    horizontalLayout->addWidget(widget);


    connect(stickyThemePickerWidget, SIGNAL(themeSelected(MereStickyTheme*)), this, SIGNAL(themeSelected(MereStickyTheme*)));

    QPalette p = palette();
    p.setColor( QPalette::Background, QColor(0, 0, 0, 50));
    setAutoFillBackground(true);
    setPalette( p );
}

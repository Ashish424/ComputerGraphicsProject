//
// Created by Priyanshu Singh on 22/11/15.
//


#ifndef CGPROJECT_UI_COASTLINETAB_HPP
#define CGPROJECT_UI_COASTLINETAB_HPP


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoastLineTab
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *rasterLabel;
    QFrame *sepLine;
    QVBoxLayout *verticalLayout;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QSpinBox *patchSpinBox;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpinBox *tokenSpinBox;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer;
    QSlider *agentThresholdSlider;
    QSpinBox *agentThresholdSpinBox;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QSpinBox *widthSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QCheckBox *showOriginalCheckBox;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QSpinBox *heightSpinBox;
    QWidget *page_3;
    QGridLayout *gridLayout;
    QSlider *boxBlurSlider;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_2;
    QSlider *stretchSlider;
    QDoubleSpinBox *sigmaYSpinBox;
    QLabel *label_16;
    QSlider *gaussBlurSlider;
    QLabel *label_15;
    QSlider *medianBlurSlider;
    QLabel *label_12;
    QDoubleSpinBox *sigmaXSpinBox;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line;
    QLabel *label_3;
    QSlider *thresholdSilder;
    QPushButton *generateBtn;

    void setupUi(QWidget *CoastLineTab)
    {
        if (CoastLineTab->objectName().isEmpty())
            CoastLineTab->setObjectName(QStringLiteral("CoastLineTab"));
        CoastLineTab->resize(471, 429);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CoastLineTab->sizePolicy().hasHeightForWidth());
        CoastLineTab->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(CoastLineTab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rasterLabel = new QLabel(CoastLineTab);
        rasterLabel->setObjectName(QStringLiteral("rasterLabel"));

        horizontalLayout->addWidget(rasterLabel);

        sepLine = new QFrame(CoastLineTab);
        sepLine->setObjectName(QStringLiteral("sepLine"));
        sepLine->setFrameShape(QFrame::VLine);
        sepLine->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sepLine);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolBox = new QToolBox(CoastLineTab);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 429, 289));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        patchSpinBox = new QSpinBox(page);
        patchSpinBox->setObjectName(QStringLiteral("patchSpinBox"));
        patchSpinBox->setMinimum(1);
        patchSpinBox->setMaximum(1000000000);

        gridLayout_2->addWidget(patchSpinBox, 0, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tokenSpinBox = new QSpinBox(page);
        tokenSpinBox->setObjectName(QStringLiteral("tokenSpinBox"));
        tokenSpinBox->setMinimum(1);
        tokenSpinBox->setMaximum(1000000000);

        gridLayout_2->addWidget(tokenSpinBox, 0, 1, 1, 1);

        label_17 = new QLabel(page);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);

        agentThresholdSlider = new QSlider(page);
        agentThresholdSlider->setObjectName(QStringLiteral("agentThresholdSlider"));
        agentThresholdSlider->setMinimum(1);
        agentThresholdSlider->setMaximum(1000000);
        agentThresholdSlider->setValue(1);
        agentThresholdSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(agentThresholdSlider, 1, 1, 1, 2);

        agentThresholdSpinBox = new QSpinBox(page);
        agentThresholdSpinBox->setObjectName(QStringLiteral("agentThresholdSpinBox"));
        agentThresholdSpinBox->setMinimum(1);
        agentThresholdSpinBox->setMaximum(1000000);

        gridLayout_2->addWidget(agentThresholdSpinBox, 1, 3, 1, 1);

        toolBox->addItem(page, QStringLiteral("Agent Properties"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 429, 289));
        sizePolicy1.setHeightForWidth(page_2->sizePolicy().hasHeightForWidth());
        page_2->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        widthSpinBox = new QSpinBox(page_2);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMinimum(1);
        widthSpinBox->setMaximum(4096);

        gridLayout_3->addWidget(widthSpinBox, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        showOriginalCheckBox = new QCheckBox(page_2);
        showOriginalCheckBox->setObjectName(QStringLiteral("showOriginalCheckBox"));

        gridLayout_3->addWidget(showOriginalCheckBox, 2, 1, 1, 1);

        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_9, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        heightSpinBox = new QSpinBox(page_2);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMinimum(1);
        heightSpinBox->setMaximum(4096);

        gridLayout_3->addWidget(heightSpinBox, 0, 3, 1, 1);

        toolBox->addItem(page_2, QStringLiteral("Image Properties"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 429, 289));
        gridLayout = new QGridLayout(page_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        boxBlurSlider = new QSlider(page_3);
        boxBlurSlider->setObjectName(QStringLiteral("boxBlurSlider"));
        boxBlurSlider->setMinimum(1);
        boxBlurSlider->setMaximum(301);
        boxBlurSlider->setSingleStep(2);
        boxBlurSlider->setValue(1);
        boxBlurSlider->setOrientation(Qt::Horizontal);
        boxBlurSlider->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(boxBlurSlider, 11, 1, 1, 3);

        line_2 = new QFrame(page_3);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 10, 0, 1, 5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 14, 0, 1, 1);

        stretchSlider = new QSlider(page_3);
        stretchSlider->setObjectName(QStringLiteral("stretchSlider"));
        stretchSlider->setMinimum(1);
        stretchSlider->setMaximum(255);
        stretchSlider->setOrientation(Qt::Horizontal);
        stretchSlider->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(stretchSlider, 9, 1, 1, 3);

        sigmaYSpinBox = new QDoubleSpinBox(page_3);
        sigmaYSpinBox->setObjectName(QStringLiteral("sigmaYSpinBox"));
        sigmaYSpinBox->setMinimum(0.01);
        sigmaYSpinBox->setSingleStep(0.01);
        sigmaYSpinBox->setValue(0.01);

        gridLayout->addWidget(sigmaYSpinBox, 2, 3, 1, 1);

        label_16 = new QLabel(page_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_16, 2, 0, 1, 1);

        gaussBlurSlider = new QSlider(page_3);
        gaussBlurSlider->setObjectName(QStringLiteral("gaussBlurSlider"));
        gaussBlurSlider->setMinimum(1);
        gaussBlurSlider->setMaximum(301);
        gaussBlurSlider->setSingleStep(2);
        gaussBlurSlider->setSliderPosition(1);
        gaussBlurSlider->setOrientation(Qt::Horizontal);
        gaussBlurSlider->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(gaussBlurSlider, 1, 1, 1, 3);

        label_15 = new QLabel(page_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_15, 2, 2, 1, 1);

        medianBlurSlider = new QSlider(page_3);
        medianBlurSlider->setObjectName(QStringLiteral("medianBlurSlider"));
        medianBlurSlider->setMinimum(1);
        medianBlurSlider->setMaximum(301);
        medianBlurSlider->setSingleStep(2);
        medianBlurSlider->setOrientation(Qt::Horizontal);
        medianBlurSlider->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(medianBlurSlider, 13, 1, 1, 3);

        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        sigmaXSpinBox = new QDoubleSpinBox(page_3);
        sigmaXSpinBox->setObjectName(QStringLiteral("sigmaXSpinBox"));
        sigmaXSpinBox->setMinimum(0.01);
        sigmaXSpinBox->setSingleStep(0.01);
        sigmaXSpinBox->setValue(0.01);

        gridLayout->addWidget(sigmaXSpinBox, 2, 1, 1, 1);

        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 9, 0, 1, 1);

        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 13, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 4, 1, 1);

        line = new QFrame(page_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 5);

        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 12, 0, 1, 1);

        thresholdSilder = new QSlider(page_3);
        thresholdSilder->setObjectName(QStringLiteral("thresholdSilder"));
        thresholdSilder->setMinimum(1);
        thresholdSilder->setMaximum(255);
        thresholdSilder->setOrientation(Qt::Horizontal);
        thresholdSilder->setTickPosition(QSlider::NoTicks);

        gridLayout->addWidget(thresholdSilder, 12, 1, 1, 3);

        toolBox->addItem(page_3, QStringLiteral("Filter Properities"));

        verticalLayout->addWidget(toolBox);

        generateBtn = new QPushButton(CoastLineTab);
        generateBtn->setObjectName(QStringLiteral("generateBtn"));

        verticalLayout->addWidget(generateBtn);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(CoastLineTab);
        QObject::connect(agentThresholdSpinBox, SIGNAL(valueChanged(int)), agentThresholdSlider, SLOT(setValue(int)));
        QObject::connect(agentThresholdSlider, SIGNAL(valueChanged(int)), agentThresholdSpinBox, SLOT(setValue(int)));

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CoastLineTab);
    } // setupUi

    void retranslateUi(QWidget *CoastLineTab)
    {
        CoastLineTab->setWindowTitle(QApplication::translate("CoastLineTab", "Form", 0));
        rasterLabel->setText(QString());
        label_2->setText(QApplication::translate("CoastLineTab", "Patch Size", 0));
        label->setText(QApplication::translate("CoastLineTab", "Tokens", 0));
        label_17->setText(QApplication::translate("CoastLineTab", "Threshold", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("CoastLineTab", "Agent Properties", 0));
        label_8->setText(QApplication::translate("CoastLineTab", "Width", 0));
        label_7->setText(QApplication::translate("CoastLineTab", "Original", 0));
        showOriginalCheckBox->setText(QString());
        label_9->setText(QApplication::translate("CoastLineTab", "Height", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("CoastLineTab", "Image Properties", 0));
        label_16->setText(QApplication::translate("CoastLineTab", "Sigma X", 0));
        label_15->setText(QApplication::translate("CoastLineTab", "Sigma Y", 0));
        label_12->setText(QApplication::translate("CoastLineTab", "Box Blur", 0));
        label_10->setText(QApplication::translate("CoastLineTab", "Gaussian Blur", 0));
        label_14->setText(QApplication::translate("CoastLineTab", "Stretch Value", 0));
        label_13->setText(QApplication::translate("CoastLineTab", "Median Blur", 0));
        label_3->setText(QApplication::translate("CoastLineTab", "Threshold", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("CoastLineTab", "Filter Properities", 0));
        generateBtn->setText(QApplication::translate("CoastLineTab", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class CoastLineTab: public Ui_CoastLineTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CGPROJECT_UI_COASTLINETAB_HPP

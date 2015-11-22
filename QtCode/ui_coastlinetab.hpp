//
// Created by Priyanshu Singh on 22/11/15.
//


#ifndef CGPROJECT_UI_COASTLINETAB_HPP
#define CGPROJECT_UI_COASTLINETAB_HPP

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
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
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *tokenSpinBox;
    QLabel *label_2;
    QSpinBox *patchSpinBox;
    QWidget *page_2;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QSpinBox *widthSpinBox;
    QLabel *label_9;
    QSpinBox *heightSpinBox;
    QWidget *page_3;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QSlider *gaussBlurSlider;
    QLabel *label_12;
    QSlider *boxBlurSlider;
    QSlider *thersholdSlider;
    QLabel *label_11;
    QLabel *label_13;
    QSlider *medianBlurSlider;
    QPushButton *generateBtn;

    void setupUi(QWidget *CoastLineTab)
    {
        if (CoastLineTab->objectName().isEmpty())
            CoastLineTab->setObjectName(QStringLiteral("CoastLineTab"));
        CoastLineTab->resize(457, 300);
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
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 422, 160));
        formLayout = new QFormLayout(page);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        tokenSpinBox = new QSpinBox(page);
        tokenSpinBox->setObjectName(QStringLiteral("tokenSpinBox"));
        tokenSpinBox->setMaximum(1000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, tokenSpinBox);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        patchSpinBox = new QSpinBox(page);
        patchSpinBox->setObjectName(QStringLiteral("patchSpinBox"));
        patchSpinBox->setMaximum(1000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, patchSpinBox);

        toolBox->addItem(page, QStringLiteral("Agent Properties"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 422, 160));
        formLayout_2 = new QFormLayout(page_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        widthSpinBox = new QSpinBox(page_2);
        widthSpinBox->setObjectName(QStringLiteral("widthSpinBox"));
        widthSpinBox->setMaximum(4096);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, widthSpinBox);

        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        heightSpinBox = new QSpinBox(page_2);
        heightSpinBox->setObjectName(QStringLiteral("heightSpinBox"));
        heightSpinBox->setMaximum(4096);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, heightSpinBox);

        toolBox->addItem(page_2, QStringLiteral("Image Properties"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        formLayout_3 = new QFormLayout(page_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout_3->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_10 = new QLabel(page_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        gaussBlurSlider = new QSlider(page_3);
        gaussBlurSlider->setObjectName(QStringLiteral("gaussBlurSlider"));
        gaussBlurSlider->setMinimum(1);
        gaussBlurSlider->setMaximum(301);
        gaussBlurSlider->setSingleStep(2);
        gaussBlurSlider->setSliderPosition(1);
        gaussBlurSlider->setOrientation(Qt::Horizontal);
        gaussBlurSlider->setTickPosition(QSlider::NoTicks);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, gaussBlurSlider);

        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_12);

        boxBlurSlider = new QSlider(page_3);
        boxBlurSlider->setObjectName(QStringLiteral("boxBlurSlider"));
        boxBlurSlider->setMinimum(1);
        boxBlurSlider->setMaximum(301);
        boxBlurSlider->setSingleStep(2);
        boxBlurSlider->setValue(1);
        boxBlurSlider->setOrientation(Qt::Horizontal);
        boxBlurSlider->setTickPosition(QSlider::NoTicks);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, boxBlurSlider);

        thersholdSlider = new QSlider(page_3);
        thersholdSlider->setObjectName(QStringLiteral("thersholdSlider"));
        thersholdSlider->setMinimum(0);
        thersholdSlider->setMaximum(255);
        thersholdSlider->setSingleStep(1);
        thersholdSlider->setValue(0);
        thersholdSlider->setOrientation(Qt::Horizontal);
        thersholdSlider->setTickPosition(QSlider::NoTicks);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, thersholdSlider);

        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_13);

        medianBlurSlider = new QSlider(page_3);
        medianBlurSlider->setObjectName(QStringLiteral("medianBlurSlider"));
        medianBlurSlider->setMinimum(1);
        medianBlurSlider->setMaximum(301);
        medianBlurSlider->setSingleStep(2);
        medianBlurSlider->setOrientation(Qt::Horizontal);
        medianBlurSlider->setTickPosition(QSlider::NoTicks);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, medianBlurSlider);

        toolBox->addItem(page_3, QStringLiteral("Filter Properities"));

        verticalLayout->addWidget(toolBox);

        generateBtn = new QPushButton(CoastLineTab);
        generateBtn->setObjectName(QStringLiteral("generateBtn"));

        verticalLayout->addWidget(generateBtn);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(CoastLineTab);

        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CoastLineTab);
    } // setupUi

    void retranslateUi(QWidget *CoastLineTab)
    {
        CoastLineTab->setWindowTitle(QApplication::translate("CoastLineTab", "Form", 0));
        rasterLabel->setText(QString());
        label->setText(QApplication::translate("CoastLineTab", "Tokens", 0));
        label_2->setText(QApplication::translate("CoastLineTab", "Patch Size", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("CoastLineTab", "Agent Properties", 0));
        label_8->setText(QApplication::translate("CoastLineTab", "Width", 0));
        label_9->setText(QApplication::translate("CoastLineTab", "Height", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("CoastLineTab", "Image Properties", 0));
        label_10->setText(QApplication::translate("CoastLineTab", "Gaussian Blur", 0));
        label_12->setText(QApplication::translate("CoastLineTab", "Box Blur", 0));
        label_11->setText(QApplication::translate("CoastLineTab", "Threshold", 0));
        label_13->setText(QApplication::translate("CoastLineTab", "Median Blur", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("CoastLineTab", "Filter Properities", 0));
        generateBtn->setText(QApplication::translate("CoastLineTab", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class CoastLineTab: public Ui_CoastLineTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CGPROJECT_UI_COASTLINETAB_HPP

//
// Created by Priyanshu Singh on 01/12/15.
//

#ifndef CGPROJECT_UI_MOUNTAINTAB_HPP
#define CGPROJECT_UI_MOUNTAINTAB_HPP


#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_MountainTab
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *rasterLabel;
    QFrame *sepLine;
    QVBoxLayout *verticalLayout_3;
    QToolBox *toolBox_3;
    QWidget *page_7;
    QGridLayout *gridLayout_7;
    QSpinBox *distanceSpinBox;
    QSpinBox *m_tokenSpinBox;
    QLabel *label_28;
    QSpacerItem *horizontalSpacer_8;
    QSpinBox *startingPointSpinBoxX;
    QLabel *label_29;
    QSpinBox *startingPointSpinBoxY;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_27;
    QSpacerItem *verticalSpacer_7;
    QWidget *page_8;
    QGridLayout *gridLayout_8;
    QSpinBox *tokenMultiQSpinBox;
    QLabel *label_30;
    QDoubleSpinBox *degraderSpinBox;
    QSlider *degraderQSlider;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_32;
    QLabel *label_31;
    QSlider *LevelQSlider;
    QSpacerItem *horizontalSpacer_9;
    QSlider *tokenMultiQSlider;
    QWidget *page_9;
    QPushButton *m_generateBtn;

    void setupUi(QWidget *MountainTab)
    {
        if (MountainTab->objectName().isEmpty())
            MountainTab->setObjectName(QStringLiteral("MountainTab"));
        MountainTab->resize(474, 355);
        horizontalLayout = new QHBoxLayout(MountainTab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rasterLabel = new QLabel(MountainTab);
        rasterLabel->setObjectName(QStringLiteral("rasterLabel"));

        horizontalLayout->addWidget(rasterLabel);

        sepLine = new QFrame(MountainTab);
        sepLine->setObjectName(QStringLiteral("sepLine"));
        sepLine->setFrameShape(QFrame::VLine);
        sepLine->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sepLine);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        toolBox_3 = new QToolBox(MountainTab);
        toolBox_3->setObjectName(QStringLiteral("toolBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox_3->sizePolicy().hasHeightForWidth());
        toolBox_3->setSizePolicy(sizePolicy);
        page_7 = new QWidget();
        page_7->setObjectName(QStringLiteral("page_7"));
        page_7->setGeometry(QRect(0, 0, 432, 215));
        gridLayout_7 = new QGridLayout(page_7);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        distanceSpinBox = new QSpinBox(page_7);
        distanceSpinBox->setObjectName(QStringLiteral("distanceSpinBox"));
        distanceSpinBox->setMinimum(1);
        distanceSpinBox->setMaximum(100000);

        gridLayout_7->addWidget(distanceSpinBox, 2, 1, 1, 1);

        m_tokenSpinBox = new QSpinBox(page_7);
        m_tokenSpinBox->setObjectName(QStringLiteral("m_tokenSpinBox"));
        m_tokenSpinBox->setMinimum(1);
        m_tokenSpinBox->setMaximum(1000000);

        gridLayout_7->addWidget(m_tokenSpinBox, 0, 1, 1, 1);

        label_28 = new QLabel(page_7);
        label_28->setObjectName(QStringLiteral("label_28"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(label_28, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 1, 3, 1, 1);

        startingPointSpinBoxX = new QSpinBox(page_7);
        startingPointSpinBoxX->setObjectName(QStringLiteral("startingPointSpinBoxX"));
        startingPointSpinBoxX->setMinimum(0);
        startingPointSpinBoxX->setMaximum(4095);

        gridLayout_7->addWidget(startingPointSpinBoxX, 1, 1, 1, 1);

        label_29 = new QLabel(page_7);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_7->addWidget(label_29, 2, 0, 1, 1);

        startingPointSpinBoxY = new QSpinBox(page_7);
        startingPointSpinBoxY->setObjectName(QStringLiteral("startingPointSpinBoxY"));
        startingPointSpinBoxY->setMinimum(0);
        startingPointSpinBoxY->setMaximum(4095);

        gridLayout_7->addWidget(startingPointSpinBoxY, 1, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        label_27 = new QLabel(page_7);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_7->addWidget(label_27, 1, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_7, 3, 0, 1, 1);

        toolBox_3->addItem(page_7, QStringLiteral("Agent Properties"));
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        page_8->setGeometry(QRect(0, 0, 432, 215));
        sizePolicy1.setHeightForWidth(page_8->sizePolicy().hasHeightForWidth());
        page_8->setSizePolicy(sizePolicy1);
        gridLayout_8 = new QGridLayout(page_8);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        tokenMultiQSpinBox = new QSpinBox(page_8);
        tokenMultiQSpinBox->setObjectName(QStringLiteral("tokenMultiQSpinBox"));
        tokenMultiQSpinBox->setMinimum(1);
        tokenMultiQSpinBox->setMaximum(10);
        tokenMultiQSpinBox->setValue(1);

        gridLayout_8->addWidget(tokenMultiQSpinBox, 1, 2, 1, 1);

        label_30 = new QLabel(page_8);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_8->addWidget(label_30, 0, 0, 1, 1);

        degraderSpinBox = new QDoubleSpinBox(page_8);
        degraderSpinBox->setObjectName(QStringLiteral("degraderSpinBox"));
        degraderSpinBox->setMinimum(0.01);
        degraderSpinBox->setMaximum(0.99);
        degraderSpinBox->setSingleStep(0.01);

        gridLayout_8->addWidget(degraderSpinBox, 2, 2, 1, 1);

        degraderQSlider = new QSlider(page_8);
        degraderQSlider->setObjectName(QStringLiteral("degraderQSlider"));
        degraderQSlider->setMinimum(1);
        degraderQSlider->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(degraderQSlider, 2, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_8, 4, 0, 1, 1);

        label_32 = new QLabel(page_8);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_8->addWidget(label_32, 2, 0, 1, 1);

        label_31 = new QLabel(page_8);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_8->addWidget(label_31, 1, 0, 1, 1);

        LevelQSlider = new QSlider(page_8);
        LevelQSlider->setObjectName(QStringLiteral("LevelQSlider"));
        LevelQSlider->setMinimum(1);
        LevelQSlider->setMaximum(10);
        LevelQSlider->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(LevelQSlider, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_9, 0, 2, 1, 1);

        tokenMultiQSlider = new QSlider(page_8);
        tokenMultiQSlider->setObjectName(QStringLiteral("tokenMultiQSlider"));
        tokenMultiQSlider->setMinimum(1);
        tokenMultiQSlider->setMaximum(10);
        tokenMultiQSlider->setValue(1);
        tokenMultiQSlider->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(tokenMultiQSlider, 1, 1, 1, 1);

        toolBox_3->addItem(page_8, QStringLiteral("Level Properties"));
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        toolBox_3->addItem(page_9, QStringLiteral("Perlin Noise"));

        verticalLayout_3->addWidget(toolBox_3);

        m_generateBtn = new QPushButton(MountainTab);
        m_generateBtn->setObjectName(QStringLiteral("m_generateBtn"));

        verticalLayout_3->addWidget(m_generateBtn);


        horizontalLayout->addLayout(verticalLayout_3);


        retranslateUi(MountainTab);
        QObject::connect(tokenMultiQSlider, SIGNAL(valueChanged(int)), tokenMultiQSpinBox, SLOT(setValue(int)));
        QObject::connect(tokenMultiQSpinBox, SIGNAL(valueChanged(int)), tokenMultiQSlider, SLOT(setValue(int)));

        toolBox_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MountainTab);
    } // setupUi

    void retranslateUi(QWidget *MountainTab)
    {
        MountainTab->setWindowTitle(QApplication::translate("MountainTab", "Form", 0));
        rasterLabel->setText(QString());
        label_28->setText(QApplication::translate("MountainTab", "Tokens", 0));
        label_29->setText(QApplication::translate("MountainTab", "Distance", 0));
        label_27->setText(QApplication::translate("MountainTab", "Starting Point", 0));
        toolBox_3->setItemText(toolBox_3->indexOf(page_7), QApplication::translate("MountainTab", "Agent Properties", 0));
        label_30->setText(QApplication::translate("MountainTab", "No. of Levels", 0));
        label_32->setText(QApplication::translate("MountainTab", "Level degrader", 0));
        label_31->setText(QApplication::translate("MountainTab", "Token Multiplier", 0));
        toolBox_3->setItemText(toolBox_3->indexOf(page_8), QApplication::translate("MountainTab", "Level Properties", 0));
        toolBox_3->setItemText(toolBox_3->indexOf(page_9), QApplication::translate("MountainTab", "Perlin Noise", 0));
        m_generateBtn->setText(QApplication::translate("MountainTab", "Generate", 0));
    } // retranslateUi

};

namespace Ui {
    class MountainTab: public Ui_MountainTab {};
} // namespace Ui

QT_END_NAMESPACE


#endif //CGPROJECT_UI_MOUNTAINTAB_HPP

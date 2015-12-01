//
// Created by Ashish Aapan on 22/11/15.
//

#ifndef CGPROJECT_UI_TERRAINDISPLAYTAB_HPP
#define CGPROJECT_UI_TERRAINDISPLAYTAB_HPP





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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CGCanvas.hpp"

QT_BEGIN_NAMESPACE

class Ui_TerrainDisplayTab
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *renderWidget;
    QVBoxLayout *verticalLayout_5;
    QFrame *sepLine;
    QToolBox *toolBox_5;
    QWidget *page_9;
    QGridLayout *gridLayout_9;
    QSlider *lightingQSlider_3;
    QLabel *label_11;
    QSlider *fixedTessQSlider_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QCheckBox *wireframeCheckBox_3;
    QCheckBox *adaptTessCheckBox_3;
    QLabel *label_15;
    QSlider *maxDepthQSlider_3;
    QSpacerItem *verticalSpacer_3;
    QDoubleSpinBox *minTessSpinBox_3;
    QDoubleSpinBox *maxTessSpinBox_3;

    void setupUi(QWidget *TerrainDisplayTab)
    {
        if (TerrainDisplayTab->objectName().isEmpty())
            TerrainDisplayTab->setObjectName(QStringLiteral("TerrainDisplayTab"));
        TerrainDisplayTab->resize(400, 300);
        horizontalLayout = new QHBoxLayout(TerrainDisplayTab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        //renderWidget = new QWidget(TerrainDisplayTab);
        renderWidget = new CGCanvas();
        renderWidget->setFixedSize(640, 480);
        renderWidget->setObjectName(QStringLiteral("renderWidget"));

        horizontalLayout->addWidget(renderWidget);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        horizontalLayout->addLayout(verticalLayout_5);

        sepLine = new QFrame(TerrainDisplayTab);
        sepLine->setObjectName(QStringLiteral("sepLine"));
        sepLine->setFrameShape(QFrame::VLine);
        sepLine->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sepLine);

        toolBox_5 = new QToolBox(TerrainDisplayTab);
        toolBox_5->setObjectName(QStringLiteral("toolBox_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolBox_5->sizePolicy().hasHeightForWidth());
        toolBox_5->setSizePolicy(sizePolicy);
        page_9 = new QWidget();
        page_9->setObjectName(QStringLiteral("page_9"));
        page_9->setGeometry(QRect(0, 0, 349, 252));
        gridLayout_9 = new QGridLayout(page_9);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        lightingQSlider_3 = new QSlider(page_9);
        lightingQSlider_3->setObjectName(QStringLiteral("lightingQSlider_3"));
        lightingQSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(lightingQSlider_3, 4, 1, 1, 1);

        label_11 = new QLabel(page_9);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_9->addWidget(label_11, 4, 0, 1, 1);

        fixedTessQSlider_3 = new QSlider(page_9);
        fixedTessQSlider_3->setObjectName(QStringLiteral("fixedTessQSlider_3"));
        fixedTessQSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(fixedTessQSlider_3, 3, 1, 1, 1);

        label_12 = new QLabel(page_9);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_9->addWidget(label_12, 3, 0, 1, 1);

        label_13 = new QLabel(page_9);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_9->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(page_9);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_9->addWidget(label_14, 1, 0, 1, 1);

        wireframeCheckBox_3 = new QCheckBox(page_9);
        wireframeCheckBox_3->setObjectName(QStringLiteral("wireframeCheckBox_3"));

        gridLayout_9->addWidget(wireframeCheckBox_3, 0, 0, 1, 1);

        adaptTessCheckBox_3 = new QCheckBox(page_9);
        adaptTessCheckBox_3->setObjectName(QStringLiteral("adaptTessCheckBox_3"));

        gridLayout_9->addWidget(adaptTessCheckBox_3, 0, 1, 1, 1);

        label_15 = new QLabel(page_9);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_9->addWidget(label_15, 5, 0, 1, 1);

        maxDepthQSlider_3 = new QSlider(page_9);
        maxDepthQSlider_3->setObjectName(QStringLiteral("maxDepthQSlider_3"));
        maxDepthQSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(maxDepthQSlider_3, 5, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_3, 6, 0, 1, 1);

        minTessSpinBox_3 = new QDoubleSpinBox(page_9);
        minTessSpinBox_3->setObjectName(QStringLiteral("minTessSpinBox_3"));
        minTessSpinBox_3->setMaximum(10);
        minTessSpinBox_3->setSingleStep(0.01);

        gridLayout_9->addWidget(minTessSpinBox_3, 1, 1, 1, 1);

        maxTessSpinBox_3 = new QDoubleSpinBox(page_9);
        maxTessSpinBox_3->setObjectName(QStringLiteral("maxTessSpinBox_3"));
        maxTessSpinBox_3->setMinimum(10);
        maxTessSpinBox_3->setMaximum(20);
        maxTessSpinBox_3->setSingleStep(0.01);

        gridLayout_9->addWidget(maxTessSpinBox_3, 2, 1, 1, 1);

        toolBox_5->addItem(page_9, QStringLiteral("GL parameters"));

        horizontalLayout->addWidget(toolBox_5);


        retranslateUi(TerrainDisplayTab);

        toolBox_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TerrainDisplayTab);
    } // setupUi

    void retranslateUi(QWidget *TerrainDisplayTab)
    {
        TerrainDisplayTab->setWindowTitle(QApplication::translate("TerrainDisplayTab", "Form", 0));
        label_11->setText(QApplication::translate("TerrainDisplayTab", "Lighting", 0));
        label_12->setText(QApplication::translate("TerrainDisplayTab", "Fixed Tessellation", 0));
        label_13->setText(QApplication::translate("TerrainDisplayTab", "Max Tessellation", 0));
        label_14->setText(QApplication::translate("TerrainDisplayTab", "Min Tessellation", 0));
        wireframeCheckBox_3->setText(QApplication::translate("TerrainDisplayTab", "Wireframe", 0));
        adaptTessCheckBox_3->setText(QApplication::translate("TerrainDisplayTab", "Adaptive Tesslation", 0));
        label_15->setText(QApplication::translate("TerrainDisplayTab", "Max Depth", 0));
        toolBox_5->setItemText(toolBox_5->indexOf(page_9), QApplication::translate("TerrainDisplayTab", "GL parameters", 0));
    } // retranslateUi

};

namespace Ui {
    class TerrainDisplayTab: public Ui_TerrainDisplayTab {};
} // namespace Ui

QT_END_NAMESPACE


#endif //CGPROJECT_UI_TERRAINDISPLAYTAB_HPP

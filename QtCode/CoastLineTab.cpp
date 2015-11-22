//
// Created by Priyanshu Singh on 22/11/15.
//

#include "CoastLineTab.hpp"
#include "ui_coastlinetab.hpp"

CoastLineTab::CoastLineTab(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::CoastLineTab)
{
    ui->setupUi(this);
}

CoastLineTab::~CoastLineTab()
{
    delete ui;
}
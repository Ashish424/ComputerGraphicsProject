//
// Created by Ashish Aapan on 13/10/15.
//


#include "FindDialog.h"
#include <QtGui>
#include <QDialog>
#include <QPushButton>
#include <QtWidgets/qboxlayout.h>


void FindDialog::findClicked() {



    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive;
    if (backwardCheckBox->isChecked()) {
        emit findPrevious(text, cs);
    } else {
        emit findNext(text, cs);
    }


}

void FindDialog::enableFindButton(const QString &text) {

    findbutton->setEnabled(!text.isEmpty());
}

FindDialog::FindDialog(QWidget *parent):QDialog(parent) {


    label  = new QLabel(tr("Hello world!"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);


    caseCheckBox = new QCheckBox(tr("Match Case"));
    backwardCheckBox = new QCheckBox(tr("Find"));
    findbutton = new QPushButton(tr("Find"));
    findbutton->setDefault(true);
    findbutton->setEnabled(false);
    closeButton = new QPushButton(tr("Close"));

    QObject::connect(lineEdit, SIGNAL(textChanged(const QString &)),
                     this, SLOT(enableFindButton(const QString &)));
    QObject ::connect(findbutton, SIGNAL(clicked()),
                      this, SLOT(findClicked()));
    QObject::connect(closeButton, SIGNAL(clicked()),
                     this, SLOT(close()));
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findbutton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());

}

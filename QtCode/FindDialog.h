//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_FINDDIALOG_H
#define CGPROJECT_FINDDIALOG_H


#include <QDialog>
#include <QLabel>

#include <QtWidgets/qlineedit.h>
#include <qcheckbox.h>


class FindDialog: public QDialog {
Q_OBJECT
public:
    FindDialog(QWidget *parent = nullptr);

signals:

    void findNext(const QString &str, Qt::CaseSensitivity cs);

    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:

    void findClicked();

    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwardCheckBox;
    QPushButton *findbutton;
    QPushButton *closeButton;


};


#endif //CGPROJECT_FINDDIALOG_H

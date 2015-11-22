//
// Created by Priyanshu Singh on 22/11/15.
//

#ifndef CGPROJECT_COASTLINETAB_HPP
#define CGPROJECT_COASTLINETAB_HPP


#include <QWidget>

namespace Ui {
    class CoastLineTab;
}

class CoastLineTab : public QWidget
{
Q_OBJECT

public:
    explicit CoastLineTab(QWidget *parent = 0);
    ~CoastLineTab();

private:
    Ui::CoastLineTab *ui;
};

#endif //CGPROJECT_COASTLINETAB_HPP

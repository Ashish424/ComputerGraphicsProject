//
// Created by Ashish Aapan on 22/11/15.
//

#ifndef CGPROJECT_TERRAINDISPLAYTAB_HPP
#define CGPROJECT_TERRAINDISPLAYTAB_HPP

#include <QWidget>
namespace Ui {
class TerrainDisplayTab;
}

class TerrainDisplayTab : public QWidget
{
 Q_OBJECT

public:
    explicit TerrainDisplayTab(QWidget *parent = 0);
    ~TerrainDisplayTab();

 private:
  Ui::TerrainDisplayTab *ui;
};


#endif //CGPROJECT_TERRAINDISPLAYTAB_HPP

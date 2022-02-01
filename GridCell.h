#ifndef GRIDCELL_H
#define GRIDCELL_H


#include <QWidget>
#include <QtWidgets>
#include "BattleshipGamePage.h"

/**
* \file GridCell.h
* \brief Manages the game buttons during gameplay
* initializes the grid cells and the booleans that indicate the presence of a ship part. Initializes functions that change cells after a game move.
*/
class GridCell : public QWidget
{
    Q_OBJECT
public:
    explicit GridCell(QWidget *parent = nullptr , int shipKind=0);

    static QString chosenJsonFile;

    QPushButton* cellButton = new QPushButton("       \n\n      ");
    bool hasShipPart= false;
    bool isHit = false;

    QGridLayout* grid ;
    int shipNumber;
    int shipKind;

    void AddShipImage();

private:
    int cellSize =55;
    QImage shipImage;



private slots:
    void OnClick();

signals:

};

#endif // GRIDCELL_H

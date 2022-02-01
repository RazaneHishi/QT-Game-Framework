#ifndef BATTLESHIPGAMEPAGE_H
#define BATTLESHIPGAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>
#include "GridCell.h"


/**
* \file BattleshipGamePage.h
* \brief The main game page for Battleships
* randomly initializes the different ship grids, attempts left, corrent, and wrong answers
*/
class BattleshipGamePage : public QWidget
{
    Q_OBJECT
public:
    explicit BattleshipGamePage(QWidget *parent = nullptr);

    static int attemptsLeft;
    static int correctAnswers;//needed 7 to win
    static int wrongAnswers;//needed 4 to lose

    int finalGrid[4][4];

    static void StrikeRandomFriendlyShip();



private:

    int shipGrid1[4][4] = {{1,0,0,0} ,
                           {0,2,3,3} ,
                           {0,2,0,0} ,
                           {1,2,4,4} };

    int shipGrid2[4][4] = {{1,0,3,3} ,
                           {1,0,2,0} ,
                           {1,0,2,0} ,
                           {4,4,2,0} };

    int shipGrid3[4][4] = {{0,2,2,2} ,
                           {1,0,0,0} ,
                           {1,3,3,0} ,
                           {1,0,4,4} };

    QHBoxLayout* boxLayout;

    void SetRandomEnemyGrid();
    void SetRandomPlayerGrid();

signals:

};

#endif // BATTLESHIPGAMEPAGE_H

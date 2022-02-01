#include "BattleshipGamePage.h"
#include "GridCell.h"

int BattleshipGamePage::attemptsLeft = 16;
int BattleshipGamePage::correctAnswers=0;
int BattleshipGamePage::wrongAnswers=0;
static QList<GridCell*> playerGrid;

/**
* \file BattleshipGamePage.cpp
* \brief The main game page for Battleships
* sets random distinct grids for the player and enemy, and has a separate function to strike an enemy ship.
* \author Yvan and Razane
*/
BattleshipGamePage::BattleshipGamePage(QWidget *parent) : QWidget(parent)
{
    boxLayout = new QHBoxLayout();
    SetRandomPlayerGrid();
    SetRandomEnemyGrid();

    setLayout(boxLayout);
    this->setFixedSize(1000,260);

    QPixmap battleshipBackgroundPixmap(":/BGnavyLarge.png");
    battleshipBackgroundPixmap.scaled(1000,1000);
    QPalette palette;
    palette.setBrush(QPalette::Background, battleshipBackgroundPixmap);
    setPalette(palette);
}

/**
* \brief Sets a random distinct enemy ship grid by using a rand index
*\return void
*/
void BattleshipGamePage::SetRandomEnemyGrid(){
    QGridLayout* grid = new QGridLayout();

    srand(time(0));
    int randomIndex = rand()%3;
    int chosenGrid[4][4];
    GridCell *rightGrid[16];

    if (randomIndex==0)memcpy(chosenGrid , shipGrid1 , 16*sizeof (int));
    else if (randomIndex==1) memcpy(chosenGrid , shipGrid2 , 16*sizeof (int));
    else memcpy(chosenGrid , shipGrid3 , 16*sizeof (int));

    for (int i=0 ; i<16 ; i++){
        int gridIndex_i = i/4;
        int gridIndex_j = i%4;
        GridCell* cell =new GridCell(nullptr ,chosenGrid[gridIndex_i][gridIndex_j]);

        rightGrid[i]= cell;
        cell->cellButton->setStyleSheet("background-color:blue");
        cell->shipNumber = i;
        grid->addWidget(cell->cellButton , 1+gridIndex_i , 8+gridIndex_j);
    }
    boxLayout->addItem(grid);
}

/**
* \brief Sets a random distinct player ship grid by using a rand index
*\return void
*/
void BattleshipGamePage::SetRandomPlayerGrid(){


    QGridLayout* grid = new QGridLayout();
    srand(time(nullptr));
    int randomIndex = rand()%3;
    int chosenGrid[4][4];


    if (randomIndex==0)memcpy(chosenGrid , shipGrid2 , 16*sizeof (int));
    else if (randomIndex==1) memcpy(chosenGrid , shipGrid1 , 16*sizeof (int));
    else memcpy(chosenGrid , shipGrid2 , 16*sizeof (int));

    //pass chosen grid to global variable
    memcpy(finalGrid , chosenGrid , 16*sizeof (int));

    for (int i=0 ; i<16 ; i++){
        int gridIndex_i = i/4;
        int gridIndex_j = i%4;
        GridCell* cell =new GridCell(nullptr ,chosenGrid[gridIndex_i][gridIndex_j]);

        cell->isHit=true;
        cell->shipKind= chosenGrid[gridIndex_i][gridIndex_j];
        cell->AddShipImage();

        if(cell->shipKind!=0) playerGrid.append( cell);

        //set color
        cell->cellButton->setStyleSheet("background-color:blue");

        grid->addWidget(cell->cellButton , 1+gridIndex_i , 8+gridIndex_j);
    }
    boxLayout->addItem(grid);
}

/**
* \brief If a question is answered correctly, this function is called to show an explosioin icon on the hit ship.
*\return void
*/
void BattleshipGamePage::StrikeRandomFriendlyShip(){
    srand(time(0));
    int randIndex = rand()% playerGrid.size();
    playerGrid.at(randIndex)->cellButton->setIcon(QIcon(":/explosion-icon-21.png"));
    playerGrid.removeAt(randIndex);
}


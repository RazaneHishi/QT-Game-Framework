#include "GridCell.h"
#include "BattleshipGamePage.h"
#include "AccountsUIhandler.h"

QString GridCell::chosenJsonFile;
static QList<int> availableQuestions;

/**
* \file GridCell.cpp
* \brief Manages Battleship's individual grid cells
* checks on click if a selected grid is marked with a ship, if yes, accesses a JSON file with distinct questions to display at random.
* Has a separate function to return to main menu, update the icons and scores safter a click, and add a ship icon.
* \author Yvan and Razane
*/
GridCell::GridCell(QWidget *parent , int shipKind) : QWidget(parent)
{
     BattleshipGamePage::attemptsLeft=16;
     BattleshipGamePage::correctAnswers=0;
     BattleshipGamePage::wrongAnswers=0;
    if (availableQuestions.size()==0)
        for (int i=0;i<10;i++)
            availableQuestions<<(i);

    this->hasShipPart = shipKind!=0;
    this->shipKind = shipKind;
    grid =new QGridLayout();

    cellButton->setFixedSize(cellSize,cellSize);
    grid->addWidget(cellButton , 0 , 0);
    setLayout(grid);

    QObject::connect(cellButton , SIGNAL(clicked()) , this , SLOT(OnClick()));
}


/**
* \brief Reveals a ship icon if the grid cell is shot depending on the type of ship initalized in the initial grid.
*\return void
*/
void GridCell::AddShipImage(){
    if (shipKind==0)
        cellButton->setIcon(QIcon(":/wave_sea_ocean-512.webp"));
    else if (shipKind==1)
        cellButton->setIcon(QIcon(":/ship-icon-1.png"));
    else if (shipKind==2)
        cellButton->setIcon(QIcon(":/boat-logistic-transportation-deleivery-vehicle-ship-container-parcel-1-20214.png"));
    else if (shipKind==3)
        cellButton->setIcon(QIcon(":/ship-icon-5.png"));
    else if (shipKind==4)
        cellButton->setIcon(QIcon(":/smallShip.png"));

    cellButton->setIconSize(QSize(55,55));
}


/**
* \brief Checks if a ship is hit and displays a random unique question from the JSON file. Otherwise displays a wave icon.
* If the question is answered correctly, a hit icon is displayed. Otherwise, the ship icon remains.
* The attemps left is decremented after each play.
*\return void
*/
void GridCell::OnClick(){
    if (isHit) return;

    isHit=true;

    if(hasShipPart){

        QFile file("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/"+chosenJsonFile);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QJsonArray questionsArray = QJsonDocument::fromJson(file.readAll()).array();

        srand(time(nullptr));
        int randIndex = availableQuestions.at(rand()%availableQuestions.size() ) ;

        QString questionNum= questionsArray[randIndex].toObject().keys()[0];
        QString question = questionsArray[randIndex].toObject().value(questionNum).toObject().keys()[0];
        QString correctAnswer= questionsArray[randIndex].toObject().value(questionNum).toObject().value(question).toString();

        QInputDialog* dialog = new QInputDialog();
        QString yesText ="Yes";
        QString noText ="No";
        bool answerIsFalse= true;


        QStringList answers;
        answers <<"choose answer"<< yesText <<noText;

        QString chosenAnswer = dialog->getItem(0 , "ANSWER THE FOLLOWING QUESTION",question , answers , 0 , false, &answerIsFalse);


        if(chosenAnswer==correctAnswer){
            cellButton->setIcon(QIcon(":/explosion-icon-21.png"));
            cellButton->setIconSize(QSize(55,55));

            answerIsFalse=false;
            availableQuestions.removeAll(randIndex);
            BattleshipGamePage::attemptsLeft--;
            BattleshipGamePage::correctAnswers++;
        }
        else if (answerIsFalse==true && chosenAnswer!="choose answer"){
            BattleshipGamePage::StrikeRandomFriendlyShip();
            AddShipImage();
            availableQuestions.removeAll(randIndex);
            BattleshipGamePage::attemptsLeft--;
            BattleshipGamePage::wrongAnswers++;
        }
        else{
            isHit=false;
            return;
        }
    }
    else{
        cellButton->setIcon(QIcon(":/wave_sea_ocean-512.webp"));
        cellButton->setIconSize(QSize(55,55));
        BattleshipGamePage::attemptsLeft--;
    }
    if (BattleshipGamePage::attemptsLeft==0)
        AccountsUIhandler::GoToPage(8);


}




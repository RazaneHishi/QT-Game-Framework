#include "ScoreHistoryPage.h"
#include "AccountsUIhandler.h"

/**
* \file ScoreHistoryPage.cpp
* \brief A user's game score history.
* Accesses the user's entry in the JSON file to display their score history in both games.
* Has a separate function to return to a signed in user's account information.
* \author Yvan and Razane
*/
ScoreHistoryPage::ScoreHistoryPage(QWidget *parent) : QWidget(parent)
{
    scoreHistoryLabel= new QLabel("Score History of "+ AccountsUIhandler::currentlyLoggedInUsername);

    //background
    QPixmap WelcomeBackgroundPixmap(":/MainBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    scoreHistoryLabel->setFont(font);
    backButton->setFont(font);

    QGridLayout *grid = new QGridLayout();
    grid->addWidget(scoreHistoryLabel , 1 , 0);
    grid->addWidget(backButton , 7 , 5);


    QFile file("//home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/data.JSON");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonArray userArray = QJsonDocument::fromJson(file.readAll()).array();
    for (int i=0;i<userArray.size();i++)
        if (userArray[i].toObject().keys()[0] == AccountsUIhandler::currentlyLoggedInUsername){
            wins1Label = new QLabel("ship quiz wins: "+  userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins1").toString());
            losses1Label = new QLabel("ship quiz losses: "+userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses1").toString());
            wins2Label = new QLabel("Shooter game wins: "+  userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins2").toString());
            losses2Label = new QLabel("Shooter game losses: "+userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses2").toString());
            bonusPoints2Label = new QLabel("Shooter game bonus points: "+userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("BonusPoints2").toString());
            break;
        }
    wins1Label->setFont(font);
    losses1Label->setFont(font);
    wins2Label->setFont(font);
    losses2Label->setFont(font);
    bonusPoints2Label->setFont(font);

    grid->addWidget(wins1Label,2,0);
    grid->addWidget(losses1Label,3,0);
    grid->addWidget(wins2Label,4,0);
    grid->addWidget(losses2Label,5,0);
    grid->addWidget(bonusPoints2Label,6,0);

    setFixedSize(900,600);
    setLayout(grid);
    QObject::connect(backButton , SIGNAL(clicked()) , this , SLOT(GoBackToAccountInfoPage()));

}

/**
* \brief Takes the currently logged in user to their account info page.
*\return void
*/
void ScoreHistoryPage::GoBackToAccountInfoPage(){
    AccountsUIhandler::DisplayAccountInfo(AccountsUIhandler::currentlyLoggedInUsername);
}

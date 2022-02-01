#include "HowToPlayPageGame2.h"

/**
* \file HowToPlayPageGame2.cpp
* \brief The instructions page for Disc Shooter.
* Lists all the game instructions on separate labels.
* Has a separate function to return to main menu.
* \author Yvan and Razane
*/
HowToPlayPageGame2::HowToPlayPageGame2(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout();

    instruction1Label= new QLabel("1- The objective of the game is to hit the highest number of Rockets.");
    instruction2Label= new QLabel("2- There are 3 types of rockets: red, green and blue.");
    instruction3Label= new QLabel("3- Red rockets are worth 3 points; Green rockets are worth 5 points; Blue rockets are worth 7 points.");
    instruction4Label= new QLabel("4– Red rockets are shot with the left arrow, green with the down arrow, and blue with the right arrow.");
    instruction5Label= new QLabel("5- To win the game, collect 150 points. Any additional points are bonuses");

    //background
    QPixmap WelcomeBackgroundPixmap(":/DiscBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",12);
    font.setBold(true);

    instruction1Label->setFont(font);
    instruction2Label->setFont(font);
    instruction3Label->setFont(font);
    instruction4Label->setFont(font);
    instruction5Label->setFont(font);
    backButton->setFont(font);

    grid->addWidget(instruction1Label,0,0);
    grid->addWidget(instruction2Label,1,0);
    grid->addWidget(instruction3Label,2,0);
    grid->addWidget(instruction4Label,3,0);
    grid->addWidget(instruction5Label,4,0);

    grid->addWidget(backButton,5,0);

    setFixedSize(900,600);
    setLayout(grid);

    QObject::connect(backButton , SIGNAL(clicked()) , this , SLOT(BackToMainMenuGame2Button()));

}

/**
* \brief Returns user to the main menu
*\return void
*/
void HowToPlayPageGame2::BackToMainMenuGame2Button(){
    AccountsUIhandler::GoToPage(9);
}

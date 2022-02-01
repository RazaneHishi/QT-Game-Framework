#include "HowToPlayPageGame1.h"
#include "AccountsUIhandler.h"

/**
* \file HowToPlayPageGame1.cpp
* \brief The instructions page for Battleships.
* Lists all the game instructions on separate labels.
* Has a separate function to return to main menu.
* \author Yvan and Razane
*/
HowToPlayPageGame1::HowToPlayPageGame1(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout();

    instruction1Label= new QLabel("1- Click on any cell on the grid to the right labeled 'Bad Coding Practices' to find the enemy ships.");
    instruction2Label= new QLabel("2- If a ship is under the chosen cell, answer the question correctly to strike the ship.");
    instruction3Label= new QLabel("3-If the question is answered correctly, the enemy ship is hit.");
    instruction4Label= new QLabel("4- If the answer is incorrect, your shot is missed and your enemy fires back, hitting one of your ships.");
    instruction5Label= new QLabel("5– If no question is found in the box, the trial is missed and the total number of attempts is reduced by 1.");
    instruction6Label= new QLabel("6- You if 7 out of 10 questions are answered correctly and fail if 4 questions are answered incorrectly.");

    //background
    QPixmap WelcomeBackgroundPixmap(":/BattleshipsBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    instruction1Label->setFont(font);
    instruction2Label->setFont(font);
    instruction3Label->setFont(font);
    instruction4Label->setFont(font);
    instruction5Label->setFont(font);
    instruction6Label->setFont(font);
    backButton->setFont(font);

    grid->addWidget(instruction1Label,0,0);
    grid->addWidget(instruction2Label,1,0);
    grid->addWidget(instruction3Label,2,0);
    grid->addWidget(instruction4Label,3,0);
    grid->addWidget(instruction5Label,4,0);
    grid->addWidget(instruction6Label,5,0);
    grid->addWidget(backButton,6,0);

    setFixedSize(900,600);
    setLayout(grid);

    QObject::connect(backButton , SIGNAL(clicked()) , this , SLOT(BackToMainMenuGame1Button()));
}

/**
* \brief Returns user to the main menu
*\return void
*/
void HowToPlayPageGame1::BackToMainMenuGame1Button(){
    AccountsUIhandler::GoToPage(5);
}

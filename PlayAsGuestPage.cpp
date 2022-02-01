#include "PlayAsGuestPage.h"
#include "AccountsUIhandler.h"

/**
* \file PlayaAsGuestPage.cpp
* \brief The play as guest page.
* declares buttons to select a game to play and a back button.
* Has a separate function to rgo to Battleships, to go to Disc Shooter, and go back to the welcome page.
* \author Yvan and Razane
*/
PlayAsGuestPage::PlayAsGuestPage(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout();

    //background
    QPixmap WelcomeBackgroundPixmap(":/MainBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",20);
    font.setBold(true);

    playGame1Button->setFont(font);
    playGame2Button->setFont(font);
    backButton->setFont(font);

    grid->addWidget(playGame1Button,0,5);
    grid->addWidget(playGame2Button,3,5);
    grid->addWidget(backButton,6,5);

    setFixedSize(900,600);
    setLayout(grid);

    QObject::connect(backButton, SIGNAL(clicked()) , this , SLOT(BackToWelcomePage()));
    QObject::connect(playGame1Button, SIGNAL(clicked()) , this , SLOT(GoToGame1()));
    QObject::connect(playGame2Button, SIGNAL(clicked()) , this , SLOT(GoToGame2()));

}

/**
* \brief Takes user to the Batteships game page.
*\return void
*/
void PlayAsGuestPage::GoToGame1(){
    AccountsUIhandler::GoToPage(5);
}

/**
* \brief Takes user to the Disc Shooter game page.
*\return void
*/
void PlayAsGuestPage::GoToGame2(){
    AccountsUIhandler::GoToPage(9);
}

/**
* \brief Takes user to the welcome page.
*\return void
*/
void PlayAsGuestPage::BackToWelcomePage(){
    AccountsUIhandler::GoToPage(0);
}


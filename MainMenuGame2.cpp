#include "MainMenuGame2.h"

/**
* \file MainMenuGame1.cpp
* \brief The main menu for Disc Shooter.
* declares a play button, a back button, and a how to play button.
* Has a separate function to return to a signed in user's account information, to display the 'how to play', and to play Disc Shooter.
* \author Yvan and Razane
*/
MainMenuGame2::MainMenuGame2(QWidget *parent) : QWidget(parent)
{
    SetGridWidgets();

    QObject::connect(backButton , SIGNAL(clicked()) , this , SLOT(BackToAccountInfoPage()));
    QObject::connect(howToPlayButton, SIGNAL(clicked()),  this, SLOT(HowToPlayGame2Page()));
    QObject::connect(playButton, SIGNAL(clicked()),  this, SLOT(GoToGame2()));
}


void MainMenuGame2::SetGridWidgets(){
    QGridLayout *grid = new QGridLayout();

    //background
    QPixmap WelcomeBackgroundPixmap(":/DiscBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",25);
    font.setBold(true);

    gameTitleLabel->setFont(font);
    playButton->setFont(font);
    howToPlayButton->setFont(font);
    backButton->setFont(font);

    grid->addWidget(gameTitleLabel,0,5);
    grid->addWidget(playButton,1,2);
    grid->addWidget(howToPlayButton,2,2);
    grid->addWidget(backButton,5,2);

    setFixedSize(900,600);
    setLayout(grid);
}

/**
* \brief Returns guest user to the welcome page and logged in user to their account info page
*\return void
*/
void MainMenuGame2::BackToAccountInfoPage(){
    if (AccountsUIhandler::currentlyLoggedInUsername!="")
        AccountsUIhandler::DisplayAccountInfo(AccountsUIhandler::currentlyLoggedInUsername);
    else
        AccountsUIhandler::GoToPage(0);
}

/**
* \brief Takes user to the how to play Disc Shooters page.
*\return void
*/
void MainMenuGame2::HowToPlayGame2Page(){

    AccountsUIhandler::GoToPage(10);
}

/**
* \brief Takes user to the Disc Shooter game page.
*\return void
*/
void MainMenuGame2::GoToGame2(){
    AccountsUIhandler::GoToPage(11);
}

/**
* \brief Takes user to the Disc Shooter game page on F1 key press.
* \event is the key pressing event triggered by pressing the F1 key.
*\return void
*/
void MainMenuGame2::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_F1 )
        GoToGame2();
}


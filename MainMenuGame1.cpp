#include "MainMenuGame1.h"

/**
* \file MainMenuGame1.cpp
* \brief The main menu for Battleships.
* declares a play button, a back button, a how to play button, and choose a topic radio buttons.
* Has a separate function to return to a signed in user's account information, to display the 'how to play', and to play Battleships.
* \author Yvan and Razane
*/
MainMenuGame1::MainMenuGame1(QWidget* parent) : QWidget (parent)
{
    SetGridWidgets();

    QObject::connect(backButton , SIGNAL(clicked()) , this , SLOT(BackToAccountInfoPage()));
    QObject::connect(howToPlayButton, SIGNAL(clicked()),  this, SLOT(HowToPlayGame1Page()));
    QObject::connect(playButton, SIGNAL(clicked()),  this, SLOT(GoToGame1()));
}

/**
* \brief Adds the background, font, buttons, and labels on the screen.
*\return void
*/
void MainMenuGame1::SetGridWidgets(){

    QGridLayout *grid = new QGridLayout();

    //background
    QPixmap WelcomeBackgroundPixmap(":/BattleshipsBg.jpg");
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
    chooseTopicLabel->setFont(font);
    topic1RadioButton->setFont(font);
    topic2RadioButton->setFont(font);

    grid->addWidget(gameTitleLabel,0,5);
    grid->addWidget(playButton,1,2);
    grid->addWidget(howToPlayButton,2,2);
    grid->addWidget(backButton,6,2);
    grid->addWidget(chooseTopicLabel , 1 , 5);
    grid->addWidget(topic1RadioButton, 2 , 5);
    grid->addWidget(topic2RadioButton , 3 , 5);

    setFixedSize(900,600);
    setLayout(grid);

}

/**
* \brief Returns guest user to the welcome page and logged in user to their account info page
*\return void
*/
void MainMenuGame1::BackToAccountInfoPage(){
    if (AccountsUIhandler::currentlyLoggedInUsername!="")
        AccountsUIhandler::DisplayAccountInfo(AccountsUIhandler::currentlyLoggedInUsername);
    else
        AccountsUIhandler::GoToPage(0);
}

/**
* \brief Takes user to the how to play Batteships page.
*\return void
*/
void MainMenuGame1::HowToPlayGame1Page(){

    AccountsUIhandler::GoToPage(6);
}

/**
* \brief Takes user to the Batteships game page.
*\return void
*/
void MainMenuGame1::GoToGame1(){
    GridCell::chosenJsonFile = (!topic2RadioButton->isChecked())? "questionsAnswers.JSON" : "foodQuestions.JSON";
    AccountsUIhandler::GoToPage(7);
}

/**
* \brief Takes user to the Batteships game page on F1 key press.
* \event is the key pressing event triggered by pressing the F1 key.
*\return void
*/
void MainMenuGame1::keyPressEvent(QKeyEvent *event){
    if (event->key()==Qt::Key_F1 )
        GoToGame1();
}



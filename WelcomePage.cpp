#include "WelcomePage.h"
#include "AccountsUIhandler.h"

static bool firstTimeOpening = true;

/**
* \file WelcomePage.cpp
* \brief The welcome page for the player.
* lets the player choose between signing in, signing up, or playing as guests.
* Has a separate function to go to a new page based on what the user selected.
* \author Yvan and Razane
*/
WelcomePage::WelcomePage(QWidget *parent) : QWidget(parent)
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

    signInRadioButton->setFont(font);
    signUpRadioButton->setFont(font);
    playAsGuestRadioButton->setFont(font);
    nextButton->setFont(font);

    grid->addWidget(signInRadioButton,0,5);
    grid->addWidget(signUpRadioButton,3,5);
    grid->addWidget(playAsGuestRadioButton,6,5);
    grid->addWidget(nextButton,7,5);

    setFixedSize(900,600);
    setLayout(grid);

     QObject::connect(nextButton, SIGNAL(clicked()), this, SLOT(HandleNextPage()));

     if (firstTimeOpening){
         firstTimeOpening=false;
         QRect screenGeometry = QApplication::desktop()->screenGeometry();
         int x = (screenGeometry.width() - this->width() )/2;
         int y = (screenGeometry.height() - this->height() )/2;
         this->move(x,y);
    }
}

/**
* \brief Goes to the page that the user specified. Either sign in, sign up, or play as guest.
*\return void
*/
void WelcomePage:: HandleNextPage(){
    int nextPageIndex=0;

    if(signUpRadioButton->isChecked()) nextPageIndex=1;
    else if(signInRadioButton->isChecked()) nextPageIndex=2;
    else if(playAsGuestRadioButton->isChecked()) nextPageIndex=3;

    AccountsUIhandler:: GoToPage(nextPageIndex);

}

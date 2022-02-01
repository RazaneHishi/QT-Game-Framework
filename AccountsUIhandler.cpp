#include "AccountsUIhandler.h"


QWidget* AccountsUIhandler:: currentPage;
DiscShooterGamePage* AccountsUIhandler::game2page;
QGraphicsView* AccountsUIhandler::graphicsView;

QString AccountsUIhandler::currentlyLoggedInUsername;

/**
* \file AccountUIhandler.cpp
* \brief Switches pages
* uses case statements when called to switch to a specified page
* Has separate functions to switch pages, display a user's information, go to Disc game, end Disc game, and set the position of a page.
* \author Yvan and Razane
*/

AccountsUIhandler::AccountsUIhandler(QWidget *parent) : QWidget(parent)
{

    currentPage = new WelcomePage();
    currentPage->show();



}

/**
* \brief Uses case statements to switch to a new page based on a given index
*\pageIndex is the page we wish to switch to
*\return void
*/
void AccountsUIhandler::GoToPage(int pageIndex)
{
    if (pageIndex!=12){
        currentPage->hide();
        delete currentPage;
    }
    switch(pageIndex){
    case 0: currentPage= new WelcomePage();
            break;
    case 1: currentPage= new SignUpForm();
            break;
    case 2: currentPage= new SignInForm();
            break;
    case 3: currentPage = new PlayAsGuestPage();
            break;
    case 4: currentPage= new ScoreHistoryPage();
            break;
    case 5: currentPage= new MainMenuGame1();
            break;
    case 6: currentPage= new HowToPlayPageGame1();
            break;
    case 7: currentPage= new BattleshipGamePage();
            break;
    case 8: currentPage = new BattleShipResults();
            break;
    case 9: currentPage = new MainMenuGame2();
            break;
    case 10: currentPage = new HowToPlayPageGame2();
            break;
    case 11: GoToGame2();return;

    case 12:EndGame2();
            currentPage = new DiscShooterResults();
            break;
    }

    SetCurrentPagePosition();
}

/**
* \brief Displays on the page the information of the currently logged in user
*\username is the currently logged in username
*\return void
*/
void AccountsUIhandler::DisplayAccountInfo(QString username){
    currentlyLoggedInUsername = username;



    currentPage->hide();

    delete currentPage;

    currentPage = new AccountInfoPage(nullptr, username);


    SetCurrentPagePosition();
}

/**
* \brief Sets a fixed position for the current page
*\name is the currently logged in username
*\return void
*/
void AccountsUIhandler::SetCurrentPagePosition(){


    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - currentPage->width() )/2;
    int y = (screenGeometry.height() - currentPage->height() )/2;
    currentPage->move(x,y);
    currentPage->show();
}

/**
* \brief Takes the player to Disc Shooter game page
*\return void
*/
void AccountsUIhandler::GoToGame2(){
    game2page= new DiscShooterGamePage();
    graphicsView = new QGraphicsView(game2page);
    graphicsView->show();


}

/**
* \brief Removes the Disc Shooter game page once the game ends
*\return void
*/
void AccountsUIhandler::EndGame2(){
    game2page->EndGame();

    graphicsView->hide();
}




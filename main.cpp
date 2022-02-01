#include <QApplication>
#include "WelcomePage.h"
#include "SignInForm.h"
#include "SignUpForm.h"
#include "AccountInfoPage.h"
#include "ScoreHistoryPage.h"
#include "PlayAsGuestPage.h"
#include "MainMenuGame1.h"
#include "HowToPlayPageGame1.h"
#include "BattleshipGamePage.h"
#include "BattleShipResults.h"
#include "MainMenuGame2.h"
#include "HowToPlayPageGame2.h"
#include "DiscShooterGamePage.h"
#include "DiscShooterResults.h"


/**
* \mainpage GameProject
* \author Yvan and Razane
* \date 11-27-2021
*/

int main(int argc, char **argv){

    QApplication app (argc, argv);

   AccountsUIhandler *auh = new AccountsUIhandler();


    return app.exec();
}

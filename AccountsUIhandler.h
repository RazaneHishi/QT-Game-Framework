#ifndef ACCOUNTSUIHANDLER_H
#define ACCOUNTSUIHANDLER_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>


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
* \file AccountUIhandler.h
* \brief Switches pages
* defines a go to page function and a display user information function acording to the loged in username
*/
class AccountsUIhandler : public QWidget
{
    Q_OBJECT
public:
    explicit AccountsUIhandler(QWidget *parent = nullptr);

public:
    static void GoToPage(int pageIndex);
    static void DisplayAccountInfo(QString username);
    static QString currentlyLoggedInUsername;


//signals:
public:

private:
    static QWidget *currentPage;
    static void SetCurrentPagePosition();
    static void GoToGame2();
    static DiscShooterGamePage* game2page;
    static QGraphicsView* graphicsView;


    static void EndGame2();

};

#endif // ACCOUNTSUIHANDLER_H

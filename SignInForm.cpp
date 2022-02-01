#include "SignInForm.h"
#include "AccountsUIhandler.h"
#include "QtDebug"

/**
* \file SignInForm.cpp
* \brief The sign in page for an existing user.
* Accesses the JSON file and iterates over the stored usernames to validate the inputted username and password.
* Has a separate function to return to the welcome menu and to sign in a user.
* \author Yvan and Razane
*/
SignInForm::SignInForm(QWidget *parent) : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout();

    passwordLine->setEchoMode(QLineEdit::Password);

    //background
    QPixmap WelcomeBackgroundPixmap(":/MainBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    userNameLabel->setFont(font);
    passwordLabel->setFont(font);
    userNameLine->setFont(font);
    passwordLine->setFont(font);
    logInButton->setFont(font);
    backButton->setFont(font);
    invalidPasswordLabel->setFont(font);

    grid->addWidget(userNameLabel,0,5);
    grid->addWidget(passwordLabel,3,5);
    grid->addWidget(userNameLine,0,7);
    grid->addWidget(passwordLine,3,7);
    grid->addWidget(logInButton,5,9);
    grid->addWidget(backButton , 5 , 0);
    grid->addWidget(invalidPasswordLabel,6,9);
    invalidPasswordLabel->hide();

    setFixedSize(900,600);
    setLayout(grid);

    QObject::connect(backButton, SIGNAL(clicked()), this, SLOT(GoBackToWelcomePage()));
    QObject::connect(logInButton, SIGNAL(clicked()),this , SLOT(SignIn()));


}

/**
* \brief Takes user to the welcome page.
*\return void
*/
void SignInForm::GoBackToWelcomePage(){
    AccountsUIhandler::GoToPage(0);
}

/**
* \brief Accesses the JSON file and iterates over the stored usernames to validate the inputted username and password.
* Displays a warning label if username and/or password are incorrect.
*\return void
*/
void SignInForm::SignIn(){


    QFile file("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/data.JSON");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonArray userArray = QJsonDocument::fromJson(file.readAll()).array();

    QString countryCode = "";


    for (int i=0;i<userArray.size();i++){
        if (userArray[i].toObject().keys()[0] == userNameLine->text() &&
                userArray[i].toObject().value(userNameLine->text()).toObject().value("password").toString()==passwordLine->text()){


            AccountsUIhandler::DisplayAccountInfo(userNameLine->text());
            return;
            }
        }



    invalidPasswordLabel->show();


}

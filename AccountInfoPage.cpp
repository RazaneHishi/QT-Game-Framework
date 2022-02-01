#include "AccountInfoPage.h"
#include "QDebug"
#include "AccountsUIhandler.h"
#include <QPixmap>


/**
* \file AccountInfoPage.cpp
* \brief Displays a user's information
* accesses a user's entry in the JSON file, extracts the information, and displays them.
* Has separate functions to set username, sign out, go to a game, and view the score history.
* \author Yvan and Razane
*/
AccountInfoPage::AccountInfoPage(QWidget *parent , QString username) : QWidget(parent)
{

    QObject::connect(signOutButton , SIGNAL(clicked()) , this  ,SLOT(SignOut()));
    QObject::connect(scoreHistoryButton , SIGNAL(clicked()) , this  ,SLOT(ScoreHistory()));
    QObject::connect(game1Button , SIGNAL(clicked()) , this  ,SLOT(GoToGame1()));
    QObject::connect(game2Button , SIGNAL(clicked()) , this  ,SLOT(GoToGame2()));



    QFile file("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/data.JSON");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonArray userArray = QJsonDocument::fromJson(file.readAll()).array();



    QString countryCode = "";
    for (int i=0;i<userArray.size();i++){
        if (userArray[i].toObject().keys()[0] == username){



            //get user full name
            fullNameLabel = new QLabel(
            userArray[i].toObject().value(username).toObject().value("firstname").toString()
            +" "+
            userArray[i].toObject().value(username).toObject().value("lastname").toString()
            );



            //get country code
            QString phoneNumber=userArray[i].toObject().value(username).toObject().value("phoneNumber").toString();
            for (int i = 1 ; i<phoneNumber.size();i++){
                if(phoneNumber[i]!="-")
                    countryCode+=phoneNumber[i];
                else
                    break;
            }


            QString profilePicColor = userArray[i].toObject().value(username).toObject().value("Profile Pic").toString();
            if (profilePicColor =="green"){
                QImage image;
                image.load(":/Green.png");
                profilePicturePixmap = QPixmap::fromImage(image).scaled(100,100);
                profilePicLabel->setPixmap(profilePicturePixmap);
            }
            else if (profilePicColor =="blue"){
                QImage image;
                image.load(":/Blue.png");
                profilePicturePixmap = QPixmap::fromImage(image).scaled(100,100);
                profilePicLabel->setPixmap(profilePicturePixmap);
            }
            else if (profilePicColor =="red"){
                QImage image;
                image.load(":/Red.png");
                profilePicturePixmap = QPixmap::fromImage(image).scaled(100,100);
                profilePicLabel->setPixmap(profilePicturePixmap);
            }
            else if (profilePicColor =="black"){
                QImage image;
                image.load(":/Black.png");
                profilePicturePixmap = QPixmap::fromImage(image).scaled(100,100);
                profilePicLabel->setPixmap(profilePicturePixmap);
            }
            else if (profilePicColor =="yellow"){
                QImage image;
                image.load(":/Yellow.png");
                profilePicturePixmap = QPixmap::fromImage(image).scaled(100,100);
                profilePicLabel->setPixmap(profilePicturePixmap);


            }



            break;
        }
    }



    if (countryCode== "961" ) {
        countryNameLabel = new QLabel("Lebanon");
        QImage image;
        image.load("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/flags/Lebanon.png");
        countryFlagPixmap = QPixmap::fromImage(image).scaled(100,50);
        countryLabel->setPixmap(countryFlagPixmap);


    }
    else if (countryCode== "963" ) {
        countryNameLabel = new QLabel("Syria");
        QImage image;
        image.load("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/flags/Syria.png");
        countryFlagPixmap = QPixmap::fromImage(image).scaled(100,50);
        countryLabel->setPixmap(countryFlagPixmap);
    }
    else if (countryCode== "970" ) {
        countryNameLabel = new QLabel("Palestine");
        QImage image;
        image.load("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/flags/Palestine.png");
        countryFlagPixmap = QPixmap::fromImage(image).scaled(100,50);
        countryLabel->setPixmap(countryFlagPixmap);
    }
    else if (countryCode== "962" ) {
        countryNameLabel = new QLabel("Jordan");
        QImage image;
        image.load("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/flags/Jordan.png");
        countryFlagPixmap = QPixmap::fromImage(image).scaled(100,50);
        countryLabel->setPixmap(countryFlagPixmap);
    }
    else if (countryCode== "20" ) {
        countryNameLabel = new QLabel("Egypt");
        QImage image;
        image.load("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/flags/Egypt.png");
        countryFlagPixmap = QPixmap::fromImage(image).scaled(100,50);
        countryLabel->setPixmap(countryFlagPixmap);
    }

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



    //current date
    currentDateDateLabel = new QLabel(QDate::currentDate().toString());



    fullNameLabel->setFont(font);
    countryNameLabel->setFont(font);
    scoreHistoryButton->setFont(font);
    game1Button->setFont(font);
    game2Button->setFont(font);
    signOutButton->setFont(font);
    currentDateWordLabel->setFont(font);
    currentDateDateLabel->setFont(font);
    countryLabel->setFont(font);
    profilePicLabel->setFont(font);


    grid->addWidget(fullNameLabel,0,5);
    grid->addWidget(countryNameLabel,1,5);
    grid->addWidget(scoreHistoryButton,7,0);
    grid->addWidget(game1Button , 5, 8);
    grid->addWidget(game2Button , 6, 8);
    grid->addWidget(signOutButton,7,8);
    grid->addWidget(currentDateWordLabel,2,0);
    grid->addWidget(currentDateDateLabel,2,5);
    grid->addWidget(countryLabel,3,0);
    grid->addWidget(profilePicLabel,3,7);

    setFixedSize(900,600);
    setLayout(grid);
    file.close();
}

/**
* \brief Sets username to currently logged in username
*\name is the currently logged in username
*\return void
*/
void AccountInfoPage::SetUserame(QString name){
    username = name;
}

/**
* \brief Signs out the current user
*\return void
*/
void AccountInfoPage::SignOut(){
    AccountsUIhandler::currentlyLoggedInUsername="";
    AccountsUIhandler::GoToPage(0);
}

/**
* \brief Takes the user to the score history page
*\return void
*/
void AccountInfoPage::ScoreHistory(){
    AccountsUIhandler::GoToPage(4);
}

/**
* \brief Takes the user to Batteships.
*\return void
*/
void AccountInfoPage::GoToGame1(){
    AccountsUIhandler::GoToPage(5);
}

/**
* \brief Takes the user to Disc Shooter.
*\return void
*/
void AccountInfoPage::GoToGame2(){
    AccountsUIhandler::GoToPage(9);
}


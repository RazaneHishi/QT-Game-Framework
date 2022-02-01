#include "DiscShooterResults.h"
#include "AccountsUIhandler.h"


/**
* \file DiscShooterResults.cpp
* \brief Displays Disc Shooter results
* displays and calculates the result and number of right and wrong anwsers. ALso accesses the user's entry in the JSON file to update their scores.
* Has a separate function to return to main menu.
* \author Yvan and Razane
*/
DiscShooterResults::DiscShooterResults(QWidget *parent) : QWidget(parent)
{

    int totalScore= DiscShooterGamePage::redScore + DiscShooterGamePage::greenScore + DiscShooterGamePage::blueScore;
    int bonusPoints= totalScore-150;

    QGridLayout* grid = new QGridLayout();

    //background
    QPixmap WelcomeBackgroundPixmap(":/DiscBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font1("Ariel",25);
    font1.setBold(true);

    QFont font2("Ariel",15);
    font1.setBold(true);

    winLabel->setFont(font1);
    loseLabel->setFont(font1);

    backButton->setFont(font2);

    QFile file("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/data.JSON");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonArray userArray = QJsonDocument::fromJson(file.readAll()).array();

    int size= userArray.size();
    //the actual user input in key,value form
    QJsonObject userInput;

    //wrapper to insert into array with key=username unique identifier and value is the personal information
    QJsonObject wrapperUserInput;

    if(totalScore>=150){

        grid->addWidget(winLabel,0,2);

        for (int i=0;i<size;i++){
            if (AccountsUIhandler::currentlyLoggedInUsername=="")break;
            if (userArray[i].toObject().keys()[0] == AccountsUIhandler::currentlyLoggedInUsername){



               QString oldWins2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins2").toString();
               int newScore= oldWins2.toInt()+1;
               QString newWins2= QString::number(newScore);

               QString oldBonusPoints2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("BonusPoints2").toString();
               int newBonus= oldBonusPoints2.toInt()+bonusPoints;
               QString newBonusPoints2= QString::number(newBonus);



               QString DOB =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("DOB").toString();
               QString ProfilePic =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Profile Pic").toString();
               QString firstName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("firstname").toString();
               QString gender =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("gender").toString();
               QString lastName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("lastname").toString();
               QString password =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("password").toString();
               QString phoneNumber =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("phoneNumber").toString();
               QString losses1 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses1").toString();
               QString wins1 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins1").toString();
               QString losses2 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses2").toString();

               userArray.removeAt(i);

               file.close();
               file.open(QIODevice::WriteOnly|QIODevice::Text);

               userInput["firstname"] =firstName;
               userInput["lastname"] = lastName;
               userInput["password"]=password;
               userInput["gender"] = gender;
               userInput["phoneNumber"]= phoneNumber;
               userInput["DOB"]= DOB;
               userInput["Profile Pic"]= ProfilePic;
               userInput["Wins1"]= wins1;
               userInput["Losses1"]= losses1;
               userInput["Wins2"]= newWins2;
               userInput["Losses2"]= losses2;
               userInput["BonusPoints2"]= newBonusPoints2;



               wrapperUserInput[AccountsUIhandler::currentlyLoggedInUsername]= userInput;
               userArray.push_back(wrapperUserInput);

               QJsonDocument newDoc( userArray);
               file.write(newDoc.toJson());
               file.close();
            }
        }

    }

    else{

         grid->addWidget(loseLabel,0,5);
         for (int i=0;i<size;i++){
             if (AccountsUIhandler::currentlyLoggedInUsername=="")break;

             if (userArray[i].toObject().keys()[0] == AccountsUIhandler::currentlyLoggedInUsername){





                QString oldLosses2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses2").toString();
                int newScore= oldLosses2.toInt()+1;
                QString newLosses2= QString::number(newScore);



                QString DOB =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("DOB").toString();
                QString ProfilePic =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Profile Pic").toString();
                QString firstName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("firstname").toString();
                QString gender =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("gender").toString();
                QString lastName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("lastname").toString();
                QString password =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("password").toString();
                QString phoneNumber =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("phoneNumber").toString();
                QString wins1 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins1").toString();
                QString losses1 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses1").toString();
                QString wins2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins2").toString();
                QString bonusPoints2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("BonusPoints2").toString();

                userArray.removeAt(i);

                file.close();
                file.open(QIODevice::WriteOnly|QIODevice::Text);

                userInput["firstname"] =firstName;
                userInput["lastname"] = lastName;
                userInput["password"]=password;
                userInput["gender"] = gender;
                userInput["phoneNumber"]= phoneNumber;
                userInput["DOB"]= DOB;
                userInput["Profile Pic"]= ProfilePic;
                userInput["Wins1"]= wins1;
                userInput["Losses1"]= losses1;
                userInput["Wins2"]= wins2;
                userInput["Losses2"]= newLosses2;
                userInput["BonusPoints2"]= bonusPoints2;



                wrapperUserInput[AccountsUIhandler::currentlyLoggedInUsername]= userInput;
                userArray.push_back(wrapperUserInput);

                QJsonDocument newDoc( userArray);
                file.write(newDoc.toJson());
                file.close();



             }
         }

    }


    QString scoreString = QString::number(totalScore) + " total points\n";
    scoreLabel= new QLabel(scoreString);

    if(totalScore>=150){
        QString bonusString = QString::number(bonusPoints) + " bonus points\n";
        bonusLabel= new QLabel(bonusString);
    } else{

        bonusLabel= new QLabel( "0 bonus points\n");
    }

    scoreLabel->setFont(font1);
    bonusLabel->setFont(font1);

    grid->addWidget(scoreLabel , 4, 3);
    grid->addWidget(bonusLabel , 5 , 3);
    grid->addWidget(backButton , 6 , 3);
    setFixedSize(900,600);
    setLayout(grid);
    QObject::connect(backButton , SIGNAL(clicked()) ,this , SLOT(backToMainMenu()) );


}

/**
* \brief Returns guest user to the main menu and logged in user to their account info page
*\return void
*/
void DiscShooterResults::backToMainMenu(){
    if (AccountsUIhandler::currentlyLoggedInUsername=="")
        AccountsUIhandler::GoToPage(3);
    else
        AccountsUIhandler::DisplayAccountInfo(AccountsUIhandler::currentlyLoggedInUsername);
}

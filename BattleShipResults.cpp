#include "BattleShipResults.h"
#include "AccountsUIhandler.h"

/**
* \file BattleShipResults.cpp
* \brief Displays Battleships results
* displays the result and number of right and wrong anwsers and accesses the user's entry in the JSON file to update their scores.
* Has a separate function to return to main menu.
* \author Yvan and Razane
*/
BattleShipResults::BattleShipResults(QWidget *parent) : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout();

    //background
    QPixmap WelcomeBackgroundPixmap(":/BattleshipsBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font1("Ariel",25);
    font1.setBold(true);

    QFont font2("Ariel",15);
    font2.setBold(true);

    backButton->setFont(font2);

    QFile file("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/data.JSON");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonArray userArray = QJsonDocument::fromJson(file.readAll()).array();

    int size= userArray.size();
    //the actual user input in key,value form
    QJsonObject userInput;

    //wrapper to insert into array with key=username unique identifier and value is the personal information
    QJsonObject wrapperUserInput;




    if (BattleshipGamePage::correctAnswers >=7){
        gameResultLabel =new QLabel("YOU WIN!");
        gameResultLabel->setFont(font1);

        for (int i=0;i<size;i++){
            if (AccountsUIhandler::currentlyLoggedInUsername=="")break;
            if (userArray[i].toObject().keys()[0] == AccountsUIhandler::currentlyLoggedInUsername){

                   qDebug()<<"inside if userArray";

               QString oldWins1= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins1").toString();
               int newScore= oldWins1.toInt()+1;
               QString newWins1= QString::number(newScore);

                qDebug()<<oldWins1<<newScore<<endl<<newWins1;

               QString DOB =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("DOB").toString();
               QString ProfilePic =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Profile Pic").toString();
               QString firstName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("firstname").toString();
               QString gender =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("gender").toString();
               QString lastName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("lastname").toString();
               QString password =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("password").toString();
               QString phoneNumber =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("phoneNumber").toString();
               QString losses1 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses1").toString();
               QString wins2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins2").toString();
               QString losses2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses2").toString();
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
               userInput["Wins1"]= newWins1;
               userInput["Losses1"]= losses1;
               userInput["Wins2"]= wins2;
               userInput["Losses2"]= losses2;
               userInput["BonusPoints2"]= bonusPoints2;

               wrapperUserInput[AccountsUIhandler::currentlyLoggedInUsername]= userInput;
               userArray.push_back(wrapperUserInput);

               QJsonDocument newDoc( userArray);
               file.write(newDoc.toJson());
               file.close();
            }
        }



    }
    else{
        gameResultLabel =new QLabel("YOU LOSE :(");
        gameResultLabel->setFont(font1);

        for (int i=0;i<size;i++){
            if (AccountsUIhandler::currentlyLoggedInUsername=="")break;

            if (userArray[i].toObject().keys()[0] == AccountsUIhandler::currentlyLoggedInUsername){



               qDebug()<<"inside if userArray";

               QString oldLosses1= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses1").toString();
               int newScore= oldLosses1.toInt()+1;
               QString newLosses1= QString::number(newScore);

               qDebug()<<oldLosses1<<newScore<<endl<<newLosses1;

               QString DOB =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("DOB").toString();
               QString ProfilePic =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Profile Pic").toString();
               QString firstName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("firstname").toString();
               QString gender =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("gender").toString();
               QString lastName =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("lastname").toString();
               QString password =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("password").toString();
               QString phoneNumber =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("phoneNumber").toString();
               QString wins1 =userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins1").toString();
               QString wins2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Wins2").toString();
               QString losses2= userArray[i].toObject().value(AccountsUIhandler::currentlyLoggedInUsername).toObject().value("Losses2").toString();
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
               userInput["Losses1"]= newLosses1;
               userInput["Wins2"]= wins2;
               userInput["Losses2"]= losses2;
               userInput["BonusPoints2"]= bonusPoints2;

               wrapperUserInput[AccountsUIhandler::currentlyLoggedInUsername]= userInput;
               userArray.push_back(wrapperUserInput);

               QJsonDocument newDoc( userArray);
               file.write(newDoc.toJson());
               file.close();



            }
        }


    }

    grid->addWidget(gameResultLabel,0,3);
    QString scoreString = QString::number(BattleshipGamePage::correctAnswers) + " correct answers\n";
    scoreString+= QString::number(BattleshipGamePage::wrongAnswers) + " wrong answers";

    scoreLabel = new QLabel(scoreString);
    scoreLabel->setFont(font1);
    grid->addWidget(scoreLabel , 0 , 2);
    grid->addWidget(backButton , 6 , 3);

    setFixedSize(900,600);
    setLayout(grid);
    QObject::connect(backButton , SIGNAL(clicked()) ,this , SLOT(backToMainMenu()) );
}

/**
* \brief Returns guest user to the main menu and logged in user to their account info page
*\return void
*/
void BattleShipResults::backToMainMenu(){
    if (AccountsUIhandler::currentlyLoggedInUsername=="")
        AccountsUIhandler::GoToPage(3);
    else
        AccountsUIhandler::DisplayAccountInfo(AccountsUIhandler::currentlyLoggedInUsername);
}

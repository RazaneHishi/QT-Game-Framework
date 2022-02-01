#include "SignUpForm.h"
#include "AccountsUIhandler.h"
#include <QString>
#include <QChar>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>

/**
* \file SignUpForm.cpp
* \brief The sign up page for a new user.
* Accesses the JSON file and adds a new entry with the inputted username and information.
* Has a separate function to add information fields to te screen, to add the user to the JSON file, and to return to the welcome menu.
* \author Yvan and Razane
*/
SignUpForm::SignUpForm(QWidget *parent) : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout();

    //background
    QPixmap WelcomeBackgroundPixmap(":/MainBg.jpg");
    WelcomeBackgroundPixmap.scaled(900,600);
    QPalette palette;
    palette.setBrush(QPalette::Background, WelcomeBackgroundPixmap);
    setPalette(palette);

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    colorLine->setFont(font);
    profilePic->setFont(font);
    badSignUpLabel->setFont(font);
    signUpButton->setFont(font);
    backButton->setFont(font);

    AddNamesAndPasswordToGrid(grid);
    AddDOBandGenderToGrid(grid);
    AddPhoneNumberToGrid(grid);

    grid->addWidget(signUpButton,11,5);
    grid->addWidget(badSignUpLabel, 12 , 5);
    grid->addWidget(profilePic , 10 , 0);
    grid->addWidget(colorLine , 10 , 1);
    grid->addWidget(backButton,13,0);


    badSignUpLabel->hide();

    setFixedSize(900,600);
    setLayout(grid);

    QObject::connect(backButton , SIGNAL(clicked()),this,SLOT(GoBackToWelcomePage()));

    QObject::connect(signUpButton, SIGNAL(clicked()), this, SLOT(AddNewUserJSON()));


}

/**
* \brief Sets the font and adds the first name, last name, and password fields for the user to input.
* \grid is the grid layout we add the name and password widgets on.
*\return void
*/
void SignUpForm::AddNamesAndPasswordToGrid(QGridLayout *grid){

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    firstNameLabel->setFont(font);
    firstNameLine->setFont(font);
    lastNameLabel->setFont(font);
    lastNameLine->setFont(font);
    usernameLabel->setFont(font);
    usernameLine->setFont(font);
    passwordLabel->setFont(font);
    passwordLine->setFont(font);
    //passwordInstructionsLabel->setFont(font);

    //first name last name
    grid->addWidget(firstNameLabel , 0 , 0);
    grid->addWidget(firstNameLine , 0 , 1);
    grid->addWidget(lastNameLabel , 1 , 0);
    grid->addWidget(lastNameLine , 1 , 1);


    //username password
    grid->addWidget(usernameLabel , 3 , 0);
    grid->addWidget(usernameLine , 3 , 1);
    grid->addWidget(passwordLabel , 4 , 0);
    //grid->addWidget(passwordInstructionsLabel , 5 , 0);
    grid->addWidget(passwordLine , 4 , 1);
    passwordLine->setEchoMode(QLineEdit::Password);
}

/**
* \brief Sets the font and adds the DOB and gender fields for the user to input.
* \grid is the grid layout we add the name and password widgets on.
*\return void
*/
void SignUpForm::AddDOBandGenderToGrid(QGridLayout* grid){

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    genderLabel->setFont(font);
    femaleRadioButton->setFont(font);
    maleRadioButton->setFont(font);
    dateOfBirthLabel->setFont(font);
    dateOfBirthDateEdit->setFont(font);

    //gender
    grid->addWidget(genderLabel, 6 , 0);
    grid->addWidget(femaleRadioButton , 6 , 1);
    grid->addWidget(maleRadioButton , 7 , 1);

    //DOB
    grid->addWidget(dateOfBirthLabel , 8 , 0);
    grid->addWidget(dateOfBirthDateEdit , 8 , 1);


}

/**
* \brief Sets the font and adds the phone number fields for the user to input.
* \grid is the grid layout we add the name and password widgets on.
*\return void
*/
void SignUpForm::AddPhoneNumberToGrid(QGridLayout* grid){

    //font
    QFont font("Ariel",10);
    font.setBold(true);

    phoneNumberLabel->setFont(font);
    phoneCountryCodeLine->setFont(font);
    phoneNumberLine->setFont(font);

    grid->addWidget(phoneNumberLabel , 9 , 0);
    grid->addWidget(phoneCountryCodeLine , 9 , 1 );
    grid->addWidget(new QLabel("-") , 9 , 3);
    grid->addWidget(phoneNumberLine , 9 , 4);
}

/**
* \brief Returns guest user to the welcome page.
*\return void
*/

void SignUpForm::GoBackToWelcomePage(){
    AccountsUIhandler::GoToPage(0);
}

/**
* \brief Opens the data JSON file and adds a new entry with key as username and value as the inputted user information.
* Once done, it displays the account information on a new page.
*\return void
*/
void SignUpForm::AddNewUserJSON(){

    //FIRST AND LAST NAME
    QString firstNametxt = firstNameLine->text();
    QString lastNametxt= lastNameLine->text();

    //USERNAME AND PASS
    QString userNametxt= usernameLine->text();
    QString passwordtxt=  passwordLine->text();
    QString dobtxt=  dateOfBirthDateEdit->text();

    //PROFILE PIC
    QString profilePictxt= "";
    if (colorLine->text()=="green" ||colorLine->text()=="red" ||colorLine->text()=="blue"
            ||colorLine->text()=="black" ||colorLine->text()=="yellow" ){
        profilePictxt= colorLine->text();
    }


    //GENDER
    QString gendertxt= "";
    if(maleRadioButton->isChecked()) gendertxt = "male";
    else if(femaleRadioButton->isChecked()) gendertxt= "female";

    // DATE OF BIRTH
    QString dateOfBirthtxt = dateOfBirthDateEdit->text();

    //PHONE NUMBER
    QString phoneNumbertxt= "";
    if (phoneCountryCodeLine->text() != "" && phoneNumberLine->text() != "")
        phoneNumbertxt = "+" + phoneCountryCodeLine->text() + "-" + phoneNumberLine->text();

    for(QChar s :phoneNumbertxt){
        if( (s != "+" && s != "-" && !s.isDigit() )){
            phoneNumbertxt="";
            break;
        }
    }
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasNumber = false;
    for (QChar s : passwordtxt){
        if (s.isDigit()) hasNumber=true;
        else if (s.isUpper()) hasUpperCase=true;
        else if (s.isLower()) hasLowerCase = true;
    }
    if (passwordtxt.length()<8 || !hasNumber || !hasLowerCase || !hasUpperCase)
        passwordtxt="";

    //username uniqueness check

    // check if any string is empty then put a label telling the user to fill teh fiels properly
    if (firstNametxt=="" || lastNametxt=="" || passwordtxt=="" || userNametxt==""
            || phoneNumbertxt=="" || profilePictxt==""){
        badSignUpLabel->show();
        return;
    }

    QFile file("/home/eece435l/repos/gameprojectgroup2/gameproject-1.0/usersJSON/data.JSON");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());


    //array with objects of key=username unique identifier and value is the personal information
    QJsonArray userArray = jsonDoc.array();

    //the actual user input in key,value form
    QJsonObject userInput;

    //wrapper to insert into array with key=username unique identifier and value is the personal information
    QJsonObject wrapperUserInput;

    QJsonObject userInfoObject= jsonDoc.object();

    for (int i=0;i<userArray.size();i++){
        if (userArray[i].toObject().keys()[0] == userNametxt){
            badSignUpLabel->show();
            file.close();
            return;
        }
    }



    file.close();
    file.open(QIODevice::WriteOnly|QIODevice::Text);

    userInput["firstname"] =firstNametxt;
    userInput["lastname"] = lastNametxt;
    userInput["password"]=passwordtxt;
    userInput["gender"] = gendertxt;
    userInput["phoneNumber"]= phoneNumbertxt;
    userInput["DOB"]= dateOfBirthtxt;
    userInput["Profile Pic"]= profilePictxt;
    userInput["Wins1"]= "0";
    userInput["Losses1"]= "0";
    userInput["Wins2"]= "0";
    userInput["Losses2"]= "0";
    userInput["BonusPoints2"]= "0";


    wrapperUserInput[userNametxt]= userInput;
    userArray.push_back(wrapperUserInput);

    QJsonDocument newDoc( userArray);
    file.write(newDoc.toJson());
    file.close();
    badSignUpLabel->hide();
    QString userInfo[] = {userNametxt , firstNametxt , lastNametxt , phoneNumbertxt , gendertxt };

    AccountsUIhandler::DisplayAccountInfo(userNametxt);
}

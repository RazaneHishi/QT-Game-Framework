#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFileDialog>
#include <QFont>

/**
* \file SignUpForm.h
* \brief The sign up page for a new user
* declares input fields for the full name, username, password, number, gender, DOB, and profile color of a new user.
*/
class SignUpForm : public QWidget
{
    Q_OBJECT
public:
    explicit SignUpForm(QWidget *parent = nullptr);

private:

    QLabel* firstNameLabel = new QLabel("Frist Name: ");
    QLineEdit* firstNameLine = new QLineEdit();

    QLabel* lastNameLabel = new QLabel("Last Name: ");
    QLineEdit* lastNameLine = new QLineEdit();


    QLabel *usernameLabel= new QLabel("Username: ");
    QLineEdit *usernameLine = new QLineEdit();
    //QLabel * passwordInstructionsLabel= new QLabel( "8 chars,include uppercase lowercase and number");

    QLabel *passwordLabel= new QLabel("Password: ");
    QLineEdit *passwordLine = new QLineEdit();


    QLabel* dateOfBirthLabel = new QLabel("Date Of Birth (MM/DD/YYYY): ");
    QDateEdit* dateOfBirthDateEdit = new QDateEdit();

    QLabel* genderLabel = new QLabel("Gender: ");
    QRadioButton* maleRadioButton = new QRadioButton("Male");
    QRadioButton* femaleRadioButton = new QRadioButton("Female");


    QLabel* phoneNumberLabel = new QLabel("Phone Number (+country code - phone number): +");
    QLineEdit* phoneCountryCodeLine = new QLineEdit();
    QLineEdit* phoneNumberLine = new QLineEdit();

    QPushButton *signUpButton= new QPushButton("Sign Up");
    QPushButton* backButton = new QPushButton("Back");
    QLabel* badSignUpLabel = new QLabel("Please make sure you have filled all fields properly");
    QLabel* profilePic= new QLabel("Type in your profile pic color (black , red, yellow, blue , green)");
    QLineEdit *colorLine = new QLineEdit();


    void AddNamesAndPasswordToGrid(QGridLayout* grid);
    void AddDOBandGenderToGrid(QGridLayout* grid);
    void AddPhoneNumberToGrid(QGridLayout* grid);
    void SelectProfilePicture(QLabel* profilePictureLabel);
    void SaveJSONfile(QString* dir);


private slots:
    void GoBackToWelcomePage();
public slots:
    void AddNewUserJSON();



};

#endif // SIGNUPFORM_H

#ifndef SIGNINFORM_H
#define SIGNINFORM_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

/**
* \file SignInForm.h
* \brief The sign in page for a registered user
* declares username and password fields.
*/
class SignInForm : public QWidget
{
    Q_OBJECT
public:
    explicit SignInForm(QWidget *parent = nullptr);

signals:

private:
    QLabel *userNameLabel= new QLabel("Username: ");
    QLabel *passwordLabel= new QLabel("Password: ");
    QLabel *invalidPasswordLabel= new QLabel("Invalid Username or Password");

    QLineEdit *userNameLine = new QLineEdit();
    QLineEdit *passwordLine = new QLineEdit();

    QPushButton *logInButton= new QPushButton("Log In");
    QPushButton* backButton = new QPushButton("Back");

private slots:
    void GoBackToWelcomePage();
    void SignIn();

};

#endif // SIGNINFORM_H

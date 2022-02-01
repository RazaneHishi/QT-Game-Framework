#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

/**
* \file WelcomePage.h
* \brief The welcome page for players
* declares sign in, sign up, and play as guest radio buttons.
*/
class WelcomePage : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomePage(QWidget *parent = nullptr);


signals:

private slots:
    void HandleNextPage();
private:

    QRadioButton *signUpRadioButton =  new QRadioButton("Sign Up");
    QRadioButton *signInRadioButton =  new QRadioButton("Sign In");
    QRadioButton *playAsGuestRadioButton =  new QRadioButton("Play as Guest");

    QPushButton *nextButton = new QPushButton("Next");


};

#endif // WELCOMEPAGE_H

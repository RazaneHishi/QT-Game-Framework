#ifndef ACCOUNTINFOPAGE_H
#define ACCOUNTINFOPAGE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QFont>

/**
* \file AccountInfoPage.h
* \brief Displays a user's information by
* initializes all user information fields and goes to game1, game2, score history, or back
*/

class AccountInfoPage : public QWidget
{
    Q_OBJECT
public:
    explicit AccountInfoPage(QWidget *parent = nullptr , QString username = "");
private:
    QString username;

    QLabel* fullNameLabel;
    QLabel* countryNameLabel;
    QLabel* currentDateWordLabel = new QLabel("Current Date");
    QLabel* currentDateDateLabel;
    QLabel* countryLabel= new QLabel();
    QPixmap countryFlagPixmap;
    QLabel* profilePicLabel = new QLabel();
    QPixmap profilePicturePixmap;
    QPushButton* scoreHistoryButton = new QPushButton("Score History");
    QPushButton* signOutButton = new QPushButton("Sign Out");
    QPushButton* game1Button = new QPushButton("Play Battleships");
    QPushButton* game2Button = new QPushButton("Play Space Shooter");

private slots:
    void SignOut();
    void ScoreHistory();
    void GoToGame1();
    void GoToGame2();

public:
    void SetUserame(QString name);

};

#endif // ACCOUNTINFOPAGE_H
